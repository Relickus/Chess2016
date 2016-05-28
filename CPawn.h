#ifndef CPAWN_H
#define	CPAWN_H

#include "CPiece.h"
#include "COLOR.h"

#define INIT_ROW 1  // ??? jak to udelam s rotaci sachovnice? prevrati se i rows nebo se to bude nejak prepocitavat?

class CPawn : public CPiece{
public:
    CPawn();
    CPawn(COLOR);
    CPawn(const CPawn& orig);
    virtual ~CPawn();

    virtual MoveList & getLegalMoves(const CBoard &  board);
    virtual int checkField(int x, int y, const CBoard& board, bool sidestep);

    
    //void printPiece() const;
      
private:
    
    //bool promoteToQueen();    // - tohle by mel udelat CController

};



#endif	/* CPAWN_H */

