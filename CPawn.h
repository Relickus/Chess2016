#ifndef CPAWN_H
#define	CPAWN_H

#include "CPiece.h"
#include "COLOR.h"

class CPawn : public CPiece{
public:
    CPawn();
    CPawn(COLOR col , int x, int y);
    virtual ~CPawn();

    virtual MoveList & getLegalMoves(const CGameSession & gS);
    MoveList & getLegalMovesUp(const CBoard &  board);
    MoveList & getLegalMovesDown(const CBoard &  board);
    virtual int checkField(int x, int y, const CBoard& board, bool sidestep);

    virtual CPiece* copyPiece(CPiece* pcs);

    
    //void printPiece() const;
      
private:
    
    //bool promoteToQueen();    // - tohle by mel udelat CController

};



#endif	/* CPAWN_H */

