#ifndef CKNIGHT_H
#define	CKNIGHT_H

#include "CPiece.h"
#include "COLOR.h"

class CKnight : public CPiece{
public:
    CKnight();
    CKnight(COLOR col , int x, int y);
    CKnight(const CKnight& orig);
    virtual ~CKnight();

    virtual MoveList & getLegalMoves(const CBoard &  board);

    

    //void printPiece() const;
    
private:

};



#endif	/* CKNIGHT_H */

