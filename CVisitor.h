#ifndef CVISITOR_H
#define	CVISITOR_H

#include "AllPieces.h"

class CVisitor {
public:
    CVisitor();
    CVisitor(const CVisitor& orig);
    virtual ~CVisitor();
    
    void printPiece(CKing*) const;
    void printPiece(CQueen*) const;
    void printPiece(CKnight*) const;
    void printPiece(CBishop*) const;
    void printPiece(CTower*) const;
    void printPiece(CPawn*) const;
    
private:

};




#endif	/* CVISITOR_H */

