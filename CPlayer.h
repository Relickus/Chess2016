#ifndef COPPONENT_H
#define	COPPONENT_H

#include "MoveList.h"
#include "CBoard.h"
#include "CPiece.h"
#include "COLOR.h"
#include "CGameSession.h"
#include <vector>

using namespace std;

class CCommand;
class CGameSession;

class CPlayer {
public:
    CPlayer();
    CPlayer(const CPlayer& orig);
    virtual ~CPlayer();
    virtual MyMove getMove(CGameSession & gS) = 0;
    COLOR getPlayerColor() const;
    COLOR setPlayerColor(COLOR col);
    void findAllFigures(const CBoard & board);
    virtual CCommand getCommand(CGameSession & gS) = 0;
    
protected:
    
    COLOR playerColor;
    vector<CPiece*>figuresVec;
    MoveList allMoves;

};




#endif	/* COPPONENT_H */

