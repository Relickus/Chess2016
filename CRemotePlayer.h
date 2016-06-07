#ifndef CREMOTEPLAYER_H
#define	CREMOTEPLAYER_H

#include "CNetworking.h"
#include "CPlayer.h"

class CRemotePlayer : public CPlayer{
public:
    CRemotePlayer();
    virtual ~CRemotePlayer();
    virtual CCommand getCommand(CGameSession& gS);
    virtual MyMove getMove(CGameSession& gS);


private:
    
    CNetworking net;
};



#endif	/* CREMOTEPLAYER_H */

