#ifndef CTOWER_H
#define	CTOWER_H

#include "COLOR.h"
#include "CPiece.h"

class CTower : public CPiece{
public:
    CTower();
    CTower(COLOR col,int x, int y);
    virtual ~CTower();

    virtual MoveList & getLegalMoves(const CGameSession & gS);
    virtual CPiece* copyPiece(const CPiece * pcs) const;

};



#endif	/* CTOWER_H */

