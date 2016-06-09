#ifndef CKNIGHT_H
#define	CKNIGHT_H

#include "CPiece.h"
#include "COLOR.h"

class CKnight : public CPiece{
public:
    CKnight();
    CKnight(COLOR col , int x, int y);
    virtual ~CKnight();

    virtual MoveList & getLegalMoves(const CGameSession & gS);
    virtual CPiece* copyPiece(const CPiece * pcs) const;

};



#endif	/* CKNIGHT_H */

