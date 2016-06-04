#ifndef CQUEEN_H
#define	CQUEEN_H

#include "CPiece.h"
#include "COLOR.h"

class CQueen : public CPiece {
public:
    CQueen();
    CQueen(COLOR col,int x, int y);
    CQueen(const CQueen& orig);
    virtual ~CQueen();

    virtual MoveList & getLegalMoves(const CBoard & board);


    //    void printPiece() const;

private:

};



#endif	/* CQUEEN_H */

