#ifndef CINTELLIGENCE_H
#define	CINTELLIGENCE_H

#include "DIFFICULTY.h"

#include "CPlayer.h"


class CIntelligence : public CPlayer {
public:
    CIntelligence();
    CIntelligence(int d);
    virtual ~CIntelligence();
    void changeDifficulty(int d);
    void think() const;
    virtual MyMove getMove(CGameSession & gamesess);
    virtual CCommand getCommand(CGameSession & gS);
    int getBestIdx(MoveList & list,CBoard & board) const;

    
    
private:
    
    void eraseCheckMoves(MoveList & l, CGameSession & gS) const;
    int difficulty;
};




#endif	/* CINTELLIGENCE_H */

