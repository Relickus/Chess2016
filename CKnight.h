#ifndef CKNIGHT_H
#define	CKNIGHT_H

#include "CPiece.h"
#include "COLOR.h"

class CKnight : public CPiece{
public:
    CKnight();
    CKnight(COLOR);
    CKnight(const CKnight& orig);
    virtual ~CKnight();
    

    void printPiece() const;

private:

};



#endif	/* CKNIGHT_H */

