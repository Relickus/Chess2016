#ifndef CQUEEN_H
#define	CQUEEN_H

#include "CPiece.h"
#include "COLOR.h"

class CQueen : public CPiece{
public:
    CQueen();
    CQueen(COLOR color);
    CQueen(const CQueen& orig);
    virtual ~CQueen();
    

    void printPiece() const;

private:

};



#endif	/* CQUEEN_H */

