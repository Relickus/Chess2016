#ifndef CSERVER_H
#define	CSERVER_H

/**
 * 
 * Class performing all server operations
 * 
 */

class CServer {
public:
    CServer();
    /**
 *  Waits for players to connect. The game starts when both players have connected.
 *
 */
    void waitForPlayers();
    
/**
 *  Sets a socket to a socket of a connected player
 *
 * @param socket of a connected player
 *
 */
    void setPlayerSocket(int sock);
    
/**
 *  Sends a signal to the players to start a their game
 *
 */
    void sendGoSignal() const; 
   
    /**
 *  Returns a socket of the second player
 *
 * @param socket of one of the players
 * 
 * @retval socket of the second player
 */
    int theOtherSocket(int sock) const;
    void closeClient(int & cliSocket);
    
 
/**
 *  Stops the server and closes clients
 */
    void stopServer();
    
    /**
     *  Initialization of the server
     *
     *
     * @retval returns -1 for fail and 0 for successful completion
     */
    int startServer();
    
    /**
     *  Services the client (player)
     *
     * @param socket of the client being served
     *
     * @retval returns 1 for fail of input read from client or when  one of the clients ends the game
     */
    int serveClient(int fromSock);
    
    /**
     * Opens a server socket
     *
     * NOTE: This function is borrowed from network code snippet on a website of subject BI-PA2. <a href="https://edux.fit.cvut.cz/courses/BI-PA2/semestralka">edux.fit.cvut.cz</a>
     *
     * @param IP adress of a server read from user
     * @param port read from user
     *
     * @retval returns server socket
     */
    friend int openSrvSocket(const char * srvName, int srvPort);


private:
    
    int cliSocket1; ///< socket of the first connected player
    int cliSocket2; ///< socket of the second connected player
    int srvSocket;  ///< socket of the server
    
    bool playersConnected;   ///< both players have connected?
};



#endif	/* CSERVER_H */

