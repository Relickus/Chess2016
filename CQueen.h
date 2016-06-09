#ifndef CQUEEN_H
#define	CQUEEN_H

#include "CPiece.h"
#include "COLOR.h"

class CQueen : public CPiece {
public:
    CQueen();
    CQueen(COLOR col,int x, int y);
    virtual ~CQueen();

    virtual MoveList & getLegalMoves(const CGameSession & gS);
    virtual CPiece* copyPiece(const CPiece * pcs) const;

};



#endif	/* CQUEEN_H */

