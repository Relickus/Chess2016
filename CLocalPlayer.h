#ifndef CHUMANPLAYER_H
#define	CHUMANPLAYER_H

#include "CPlayer.h"

/**
 * Class representing a local player on this PC
 */
class CLocalPlayer : public CPlayer{
public:
    CLocalPlayer();
    virtual ~CLocalPlayer();
    /**
     * Gets move from local player (unused)
     * @param gS reference to instance of the game
     * @param cliSocket socket of the client
     * @return Move made by user
     */
    //virtual CMyMove getMove(const CGameSession & gS,int cliSocket=-1); 
    /**
     * Reads command from local user 
     * @return command from user in a form of string
     */
    string readInput() const;   
    /**
     * Informs user about bad input he provided.
     */
    void badInput() const;
    /**
     * Gets command from user.
     * @param gS reference to instance of the game
     * @return command received from user
     */
    virtual CCommand getCommand(const CGameSession & gS) ;

    
private:

};




#endif	/* CHUMANPLAYER_H */

