#ifndef CKING_H
#define	CKING_H

#include "CPiece.h"
#include "COLOR.h"

class CGameSession;

class CKing : public CPiece{
public:
    CKing();
    CKing(COLOR col , int x, int y);
    virtual ~CKing();
    
    bool isChecked(const CBoard & board,bool currentPlayerDown) const;

    virtual MoveList & getLegalMoves(const CGameSession & gS);
    virtual int checkField(int x, int y, const CBoard& board);

    virtual CPiece* copyPiece(const CPiece* pcs) const ;

};



#endif	/* CKING_H */

