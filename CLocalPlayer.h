#ifndef CHUMANPLAYER_H
#define	CHUMANPLAYER_H

#include "CPlayer.h"

class CLocalPlayer : public CPlayer{
public:
    CLocalPlayer();
    virtual ~CLocalPlayer();
    virtual MyMove getMove(CGameSession & gS,int cliSocket=-1); 
    string readInput() const;    
    void badInput() const;
    virtual CCommand getCommand(CGameSession & gS);

    
private:

};




#endif	/* CHUMANPLAYER_H */

