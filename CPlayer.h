#ifndef COPPONENT_H
#define	COPPONENT_H

#include "CGameSession.h"
#include "MoveList.h"
#include "CPiece.h"
#include "COLOR.h"
#include <vector>

using namespace std;

class CCommand;
class CGameSession;

class CPlayer {
public:
    CPlayer();
    virtual ~CPlayer();
    virtual MyMove getMove(CGameSession & gS) = 0;
    COLOR getPlayerColor() const;
    COLOR setPlayerColor(COLOR col);
    void findAllFigures(const CBoard & board);
    virtual CCommand getCommand(CGameSession & gS) = 0;
    bool kingIsChecked(CGameSession & gS) const;
    void setKing(CKing * k);
    
protected:
    
    COLOR playerColor;
    vector<CPiece*>figuresVec;
    MoveList allMoves;
    CKing * playersKing;
    
    friend CGameSession;
};




#endif	/* COPPONENT_H */

