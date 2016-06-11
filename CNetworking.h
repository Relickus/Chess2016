#ifndef CNETWORKING_H
#define	CNETWORKING_H
#include "COLOR.h"
#include "CMyMove.h"

class CCommand;
class CRemotePlayer;

/**
 * Performs client operations for an online game
 */
class CNetworking {
public:
    
    CNetworking();
    /**
     * Gets move from remote player
     * @param sock Socket to read from
     * @return Move read from socket
     */
    CMyMove getMove(const int sock) const;
    /**
     * Sends made command to the other player
     * @param command command to be sent - SURRENDER,EXIT or MAKEMOVE only
     * @param FromSock socket to send command to
     */
    void sendCommand(const CCommand & command,int FromSock) const;
    /**
     * Calls for opening a client socket 
     * @return client socket
     */
    int getSocket() const;
    /**
     * Waits until server sends GO signal
     * @param socket to be read from
     * @return success or failure of reading
     */
    bool waitForStart(const int socket) const;
    /**
     * Reads a color sent from server 
     * @param socket to be read from
     * @return Color received from the socket
     */
    COLOR recvPlayerColor(const int socket) const;    
    /**
     * Reads details of a server to connect to from user
     */
    void inputServerInfo();

    /**
     * Actually opens client socket
     * NOTE: this function is not mine - it is borrowed from www.edux.fit.cvut.cz
     */    
    friend int openCliSocket ( const char * srvName, int srvPort );    
    
    friend class CHostJoinMenu;
    friend class CRemotePlayer;
    
private:
    
    string host_ip; ///< IP address of a game server
    int host_port; ///< Game port on the game server
};



#endif	/* CNETWORKING_H */

