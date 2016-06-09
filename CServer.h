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
 * @brief Waits for players to connect
 *
 */
    void waitForPlayers();
    
/**
 * @brief Sets a socket to a socket of a connected player
 *
 * @param socket of a connected player
 *
 */
    void setPlayerSocket(int sock);
    
/**
 * @brief Sends a signal to the players to start a their game
 *
 */
    void sendGoSignal() const; 
   
    /**
 * @brief Returns a socket of the second player
 *
 * @param socket of one of the players
 * 
 * @retval socket of the second player
 */
    int theOtherSocket(int sock) const;
    void closeClient(int & cliSocket);
    
 
/**
 * @brief Stops the server and closes clients
 */
    void stopServer();
    
    /**
     * @brief Initialization of the server
     *
     *
     * @retval returns -1 for fail and 0 for successful completion
     */
    int startServer();
    
    /**
     * @brief Services the client (player)
     *
     * @param socket of the client being served
     *
     * @retval returns 1 for fail of input read from client or when  one of the clients ends the game
     */
    int serveClient(int fromSock);
    
    /**
     * @brief Opens a server socket
     *
     * This function is borrowed from network code snippet on website edux.fit.cvut.cz
     *
     * @param IP adress of a server read from user
     * @param port read from user
     *
     * @retval returns server socket
     */
    friend int openSrvSocket(const char * srvName, int srvPort);


private:
    
    int cliSocket1;
    int cliSocket2;
    int srvSocket;
    
    bool playersConnected;    
};



#endif	/* CSERVER_H */

