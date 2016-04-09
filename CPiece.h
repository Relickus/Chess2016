#ifndef CPIECE_H
#define	CPIECE_H

#include "COLOR.h"
#include "FIGURENAME.h"
//#include "CVisitor.h"

class CPiece {
public:
    CPiece();
    CPiece(COLOR color);
    CPiece(const CPiece& orig);
    virtual ~CPiece();
    
    bool takePiece() const;    
    FIGURENAME getName() const;
    COLOR getColor() const;
    
    virtual void printPiece() const = 0;
    
    //void acceptVisitor(const CVisitor & v) const;
    
    //CPiece & operator=(const CPiece & oth); // ?? reference na CPiece
    
private:
    
    bool moveUp();
    bool moveDown();
    bool moveLeft();
    bool moveRight();
    
    bool moveUp(unsigned);
    bool moveDown(unsigned);
    bool moveLeft(unsigned);
    bool moveRight(unsigned);

    int xPos;
    int yPos;
    COLOR color;
    FIGURENAME name;
};


#endif	/* CPIECE_H */

