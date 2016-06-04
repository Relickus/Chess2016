#ifndef CTOWER_H
#define	CTOWER_H

#include "COLOR.h"
#include "CPiece.h"

class CTower : public CPiece{
public:
    CTower();
    CTower(COLOR col,int x, int y);
    virtual ~CTower();

    virtual MoveList & getLegalMoves(const CBoard &  board);
    //virtual bool isLegalMove(int x, int y) const;


    //void printPiece() const;
private:

};



#endif	/* CTOWER_H */

