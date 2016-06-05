#ifndef CBISHOP_H
#define	CBISHOP_H

#include "CPiece.h"
#include "COLOR.h"

class CBishop : public CPiece {
public:
    CBishop();
    CBishop(COLOR col , int x, int y);
    virtual ~CBishop();
    //virtual bool isLegalMove(int x, int y) const;

    virtual MoveList & getLegalMoves(const CGameSession & gS);

    virtual CPiece* copyPiece(CPiece* pcs);



    

    //void printPiece() const;

private:

};



#endif	/* CBISHOP_H */

