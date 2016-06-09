#ifndef CSERVER_H
#define	CSERVER_H

class CServer {
public:
    CServer();
    void waitForPlayers();
    void setPlayerSocket(int sock);
    void sendGoSignal() const;
    int theOtherSocket(int sock) const;
    void closeClient(int & cliSocket);
    void stopServer();
    int startServer();
    int serveClient(int fromSock);
    
    friend int openSrvSocket(const char * srvName, int srvPort);


private:
    
    int cliSocket1;
    int cliSocket2;
    int srvSocket;
    
    bool playersConnected;    
};



#endif	/* CSERVER_H */

