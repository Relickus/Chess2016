#ifndef CPAWN_H
#define	CPAWN_H

#include "CPiece.h"
#include "COLOR.h"

class CPawn : public CPiece{
public:
    CPawn();
    CPawn(COLOR col , int x, int y);
    CPawn(const CPawn& orig);
    virtual ~CPawn();

    virtual MoveList & getLegalMoves(const CBoard &  board);
    MoveList & getLegalMovesUp(const CBoard &  board);
    MoveList & getLegalMovesDown(const CBoard &  board);
    virtual int checkField(int x, int y, const CBoard& board, bool sidestep);

    
    //void printPiece() const;
      
private:
    
    //bool promoteToQueen();    // - tohle by mel udelat CController

};



#endif	/* CPAWN_H */

