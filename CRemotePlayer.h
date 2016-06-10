#ifndef CREMOTEPLAYER_H
#define	CREMOTEPLAYER_H

#include "CNetworking.h"
#include "CPlayer.h"

class CRemotePlayer : public CPlayer{
public:
    /**
     * Initializes an instance of a remote player class
     * @param socket remote player's socket
     */
    CRemotePlayer(int socket);
    virtual ~CRemotePlayer();
     
    /**
     * gets command from remote player
     * @param gS reference to instance of a game
     * @return command received from user
     */
    virtual CCommand getCommand(const CGameSession& gS);
    /**
     * method to get move from a remote player
     * @param gS reference to instance of a game
     * @param cliSocket Socket to read move from
     * @return Move received from player
     */
    MyMove getMove(const CGameSession& gS, int cliSocket=-1);
    
    /**
     *returns this player's socket
     */
    virtual int getSocket() const;


    int cliSocket;  ///< socket for communication with server 
    
};



#endif	/* CREMOTEPLAYER_H */

