#ifndef CNETWORKING_H
#define	CNETWORKING_H
#include "COLOR.h"
#include "MyMove.h"

class CCommand;
class CRemotePlayer;

class CNetworking {
public:
    
    CNetworking();
    MyMove getMove(const int sock) const;
    void sendCommand(const CCommand & command,int FromSock) const;
    int getSocket() const;
    bool waitForStart(const int socket) const;
    COLOR recvPlayerColor(const int socket) const;    
    void inputServerInfo();

    friend int openCliSocket ( const char * srvName, int srvPort );    
    
    friend class CHostJoinMenu;
    friend class CRemotePlayer;
    
private:
    
    string host_ip;
    int host_port;
};



#endif	/* CNETWORKING_H */

