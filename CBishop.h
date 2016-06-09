#ifndef CBISHOP_H
#define	CBISHOP_H

#include "CPiece.h"
#include "COLOR.h"

class CBishop : public CPiece {
public:
    CBishop();
    CBishop(COLOR col , int x, int y);
    virtual ~CBishop();

    virtual MoveList & getLegalMoves(const CGameSession & gS);
    virtual CPiece* copyPiece(const CPiece* pcs) const ;


};



#endif	/* CBISHOP_H */

