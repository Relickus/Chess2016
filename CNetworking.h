#ifndef CNETWORKING_H
#define	CNETWORKING_H
#include "COLOR.h"
#include "MyMove.h"

class CCommand;
class CRemotePlayer;

class CNetworking {
public:
    
    void clientReady(int sock);
    MyMove getMove(int sock) const;
    void sendCommand(CCommand & command,int FromSock) const;
    int getSocket();
    bool waitForStart(int socket) const;
    COLOR recvPlayerColor(int socket) const;    

    //int openSrvSocket ( const char * srvName, int srvPort);
    //void serveClient ( int s );
    
    friend int openCliSocket ( const char * srvName, int srvPort );
    
    
    friend class CHostJoinMenu;
    friend class CRemotePlayer;
    
private:
    
};



#endif	/* CNETWORKING_H */

