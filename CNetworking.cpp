#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <thread>
#include <iostream>
using namespace std;

#include "CNetworking.h"

CNetworking::CNetworking() {

}

CNetworking::~CNetworking() {

}

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

void serveClient ( int s )
{
  while ( true )
  {
    char buffer[100];
    int l = recv ( s, buffer, sizeof ( buffer ), 0 );
    if ( l <= 0 ) break;

    for ( int i = 0; i < l; i ++ )
      if ( isalpha ( buffer[i] ) )
        buffer[i] ^= 0x20;

    send ( s, buffer, l, 0 );
  }
  close ( s );
}
// ===============================================================

int CNetworking::startServer(){
    
       // ------------ eduxovy snippet na site------------
    int s = openSrvSocket ( "localhost", 2666 );
  if ( s == -1 )
  {
      cout << "Nebylo mozne zalozit server." << endl;
    return 1;
  }

   cout << "Server spusten, cekam na hrace." << endl;
  while ( true )
  {
    struct sockaddr addr;
    socklen_t addrLen = sizeof ( addr );
    int cliSock = accept ( s, &addr, &addrLen );

    thread x ( serveClient, cliSock );
    x . detach ();
  }
  close ( s );
  
  // --------------------------------------------------
  
}
