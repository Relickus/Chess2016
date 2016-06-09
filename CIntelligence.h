#ifndef CINTELLIGENCE_H
#define	CINTELLIGENCE_H

#include "DIFFICULTY.h"

#include "CPlayer.h"


class CIntelligence : public CPlayer {
public:
    CIntelligence();
    CIntelligence(int d);
    void changeDifficulty(int d);
    virtual MyMove getMove(const CGameSession & gS,int cliSocket=-1);
    virtual CCommand getCommand(const CGameSession & gS);

    
private:
    
    int getBestIdx(MoveList & list,const CBoard & board) const;
    void eraseCheckMoves(MoveList & l, const CGameSession & gS);
    int difficulty;
};




#endif	/* CINTELLIGENCE_H */

