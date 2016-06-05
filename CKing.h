#ifndef CKING_H
#define	CKING_H

#include "CPiece.h"
#include "COLOR.h"
#include "CGameSession.h"

class CKing : public CPiece{
public:
    CKing();
    CKing(COLOR col , int x, int y);
    virtual ~CKing();
    
    bool isChecked(const CBoard & board) const;

    virtual MoveList & getLegalMoves(const CGameSession & gS);
    virtual int checkField(int x, int y, const CBoard& board);

    virtual CPiece* copyPiece(CPiece* pcs);




    //void printPiece() const;
private:

};



#endif	/* CKING_H */

