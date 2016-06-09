#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <iostream>
using namespace std;

#include "MyMove.h"
#include "CCommand.h"
#include "CNetworking.h"


int openCliSocket ( const char * srvName, int srvPort )
{
  struct addrinfo * ai;
  char srvPortText[10];

  snprintf ( srvPortText, sizeof ( srvPortText ), "%d", srvPort );

  if ( getaddrinfo ( srvName, srvPortText, NULL, &ai ) != 0 )
  {
    printf ( "getaddrinfo" );
    return -1;
  }

  int s = socket ( ai -> ai_family, SOCK_STREAM, 0 );
  if ( s == -1 )
  {
    freeaddrinfo ( ai );
    printf ( "socket" );
    return -1;
  }

  if ( connect ( s, ai -> ai_addr, ai -> ai_addrlen ) != 0 )
  {
    close ( s );
    freeaddrinfo ( ai );
    printf ( "connect" );
    return -1;
  }
  freeaddrinfo ( ai );
  return s;
}

MyMove CNetworking::getMove(int cliSocket) const {

    char buffer[10] = { 0 };
    int l = recv ( cliSocket, buffer, sizeof ( buffer ), 0 );
    if(l<=0){
        cout << "SPATNY PRIJATY MOVE!" << endl;
        return MyMove(-1,-1,-1,-1);
    }
    
    if(strcmp(buffer,"EXIT")==0)
        return MyMove(-2,-2,-2,-2);
    
    printf("prijal jsem move: %s|\n",buffer);
    
    MyMove m(buffer);
    
    return m;
}

void CNetworking::sendCommand(CCommand & command, int FromSock ) const {

    if(FromSock == -1)
        return;
    
    fd_set rd;
    FD_ZERO ( &rd );
    FD_SET ( FromSock, &rd );
    FD_SET ( STDIN_FILENO, &rd );

    if ( FD_ISSET ( FromSock, &rd ) )
    {
        
      char buffer[100];
     
      if(command.command==MAKEMOVE){        
        command.getMoveRef().tocstring(buffer);
        printf("ODESILAM MOVE: %s|\n",buffer);
      
        send ( FromSock, buffer, 5+1, 0 );
     }
      else if(command.command==EXIT){
          cout << "Odeslan EXIT pozadavek."<<endl<<"Konec hry." << endl;
          strcpy(buffer,"EXIT");
          send ( FromSock, buffer, 4+1, 0 );
      }
     
    }
    
}


int CNetworking::getSocket() {

    return openCliSocket ( "localhost", 2666 );
}

void CNetworking::clientReady(int sock){
    
    cout << "Posilam ready..." << endl;
    send ( sock, "READY", 5+1, 0 );
    
}

bool CNetworking::waitForStart(int socket) const {

    char buffer[10] = {0};    
    
    cout << "Waiting for opponent to connect." << endl;
    int l = recv ( socket, buffer, sizeof ( buffer ), 0 );
    if(l<0){
        cout << "NEJAKA CHYBA VE WAITFORSTART" << endl;
        printf("obdrzeno: |%s|\n",buffer);
        return false;
    }   
    else if(buffer[0]=='G' && buffer[1]=='0' && buffer[2]==0 ){
        cout << "SERVER SENT GO" << endl;
        return true;
    }
    
    return false;
}

COLOR CNetworking::recvPlayerColor(int socket) const{

    char buffer[3] = { 0 };
    
    int l = recv ( socket, buffer, sizeof ( buffer ), 0 );
    if(l<=0){
        cout << "Chyba ve cteni barvy!" << endl;
        return WHITE;
    }
    
    else{
        
        if(buffer[0] == 'W' && buffer[1] == 0)
            return WHITE;
        else if(buffer[0] == 'B' && buffer[1] == 0)
            return BLACK;
        else {
            cout << "RECEIVED UNKNOWN COLOR" << endl;
            return WHITE;
        }
    }
    
}
