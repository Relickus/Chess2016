#ifndef CREMOTEPLAYER_H
#define	CREMOTEPLAYER_H

#include "CNetworking.h"
#include "CPlayer.h"

class CRemotePlayer : public CPlayer{
public:
    CRemotePlayer(int socket);
    virtual CCommand getCommand(const CGameSession& gS);
    virtual MyMove getMove(const CGameSession& gS, int cliSocket=-1);
    virtual int getSocket() const;


    int cliSocket;
    int enemySocket;
    
};



#endif	/* CREMOTEPLAYER_H */

