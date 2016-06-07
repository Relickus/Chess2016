#ifndef CNETWORKING_H
#define	CNETWORKING_H

class CNetworking {
public:
    CNetworking();
    virtual ~CNetworking();
    int startServer();
    //int openSrvSocket ( const char * srvName, int srvPort);
    //void serveClient ( int s );

    
private:

    friend class CHostJoinMenu;
    friend int openSrvSocket( const char *, int);
    friend void serveClient(int);
};



#endif	/* CNETWORKING_H */

