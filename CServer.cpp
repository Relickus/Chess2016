#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <iostream>
//------- includy pro sitovani-----------

using namespace std;

#include "CServer.h"
#include "CRemotePlayer.h"

// ========================= FUNKCE ================================


int openSrvSocket ( const char * srvName, int srvPort )
{
  struct addrinfo * ai;
  char srvPortText[10];

  snprintf ( srvPortText, sizeof ( srvPortText ), "%d", srvPort );

  if ( getaddrinfo ( srvName, srvPortText, NULL, &ai ) != 0 )
  {
    printf ( "getaddrinfo\n" );
    return -1;
  }

  int s = socket ( ai -> ai_family, SOCK_STREAM, 0 );
  if ( s == -1 )
  {
    freeaddrinfo ( ai );
    printf ( "socket\n" );
    return -1;
  }

  if ( bind ( s, ai -> ai_addr, ai -> ai_addrlen ) != 0 )
  {
    close ( s );
    freeaddrinfo ( ai );
    printf ( "bind\n" );
    return -1;
  }

  if ( listen ( s, 5 ) != 0 )
  {
    close ( s );
    freeaddrinfo ( ai );
    printf ( "listen\n" );
    return -1;
  }
  freeaddrinfo ( ai );
  return s;
}

int CServer::serveClient ( int fromSock )
{
    char buffer[10] = { 0 };
    cout << "Cekam na tah od: "<<(fromSock==cliSocket1?"HRACE 1":"HRACE 2") << endl;
    int l = recv ( fromSock, buffer, sizeof ( buffer ), 0 );
    
    if( l <= 0 || strcmp(buffer,"EXIT")==0){
        return 1;
    }
    
    cout<<"PRIJAL JSEM TENTO RETEZEC:"<<endl;
    printf("%c|%c|%c|%c|%c...\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
    cout<<"\n... OD "<< fromSock<<" a odesilam na : "<<theOtherSocket(fromSock)<<endl;
    
    
    send ( theOtherSocket(fromSock) , buffer, l, 0 );
    
    return 0;
}
// ===============================================================

int CServer::startServer(){
        
     // ------------ eduxovy snippet na site------------------
        
        srvSocket = openSrvSocket ( "localhost", 2666 );
      if ( srvSocket == -1 )
      {
          cout << "Nebylo mozne vytvorit serversocket." << endl;
        return -1;
      }

       cout << "Server spusten." << endl;
       
       waitForPlayers();
       
       while(true){
           
            if( serveClient(cliSocket1) == 1){
                cout << "Hrac 1 odpadl nebo ukoncil hru." << endl;
                break;
            }
            if( serveClient(cliSocket2) == 1){
                 cout << "Hrac 2 odpadl nebo ukoncil hru." << endl;
                break;
            }
       }
  // --------------------------------------------------
    
    cout<<"...koncim srver"<<endl;
    stopServer();
    return 0;
}
void CServer::stopServer() {

    send ( cliSocket1, "EXIT", 5, 0 );
    send ( cliSocket2, "EXIT", 5, 0 );
    
    close(cliSocket1);
    close(cliSocket2);
    close(srvSocket);
}

void CServer::closeClient(int & cliSocket){
    
    if(cliSocket != -1){
        close ( cliSocket );
    }
  
}

int CServer::theOtherSocket(int sock) const{
    
    return (sock == cliSocket1 ? cliSocket2 : cliSocket1);
}

void CServer::sendGoSignal() const {

    send ( cliSocket1, "GO", 3, 0 );
    send ( cliSocket2, "GO", 3, 0 );
}


void CServer::setPlayerSocket(int sock) {

    if(cliSocket1 == -1){
        cliSocket1 = sock;
        cout << "Hrac 1 pripojen." << endl;
        send ( sock, "W", 2, 0 );
        return;
    }
    else if(cliSocket2 == -1){
        cliSocket2 = sock;
        cout << "Hrac 2 pripojen." << endl;
        send ( sock, "B", 2, 0 );
        playersConnected=true;
        return;
    }
}


void CServer::waitForPlayers() {
    
    struct sockaddr addr;
    socklen_t addrLen;
    int sock;
    
    cout << "Cekam na pripojeni hracu..." << endl;
    while(!playersConnected){
        addrLen = sizeof ( addr );
        sock = accept ( srvSocket, &addr, &addrLen );

        setPlayerSocket(sock);        
    }
    
    cout << "SERVER:POSILAM GO" << endl;
    sendGoSignal();
    cout<<"========== Zahajuji hru! ========="<<endl;
}

CServer::CServer() : cliSocket1(-1),cliSocket2(-1),srvSocket(-1),playersConnected(false) {
}