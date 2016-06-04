#ifndef CKING_H
#define	CKING_H

#include "CPiece.h"
#include "COLOR.h"

class CKing : public CPiece{
public:
    CKing();
    CKing(COLOR col , int x, int y);
    virtual ~CKing();
    
    bool isChecked(const CBoard & board) const;

    virtual MoveList & getLegalMoves(const CBoard &  board);
    virtual int checkField(int x, int y, const CBoard& board);



    //void printPiece() const;
private:

};



#endif	/* CKING_H */

