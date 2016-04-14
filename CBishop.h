#ifndef CBISHOP_H
#define	CBISHOP_H

#include "CPiece.h"
#include "COLOR.h"

class CBishop : public CPiece {
public:
    CBishop();
    CBishop(COLOR);
    CBishop(const CBishop& orig);
    virtual ~CBishop();
    

    void printPiece() const;


private:

};



#endif	/* CBISHOP_H */

