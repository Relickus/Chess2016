#ifndef CPIECE_H
#define	CPIECE_H

#include "COLOR.h"
#include "FIGURENAME.h"

#include "MoveList.h"

#include <iostream>

#include "CBoard.h"

//#include "CVisitor.h"

class CPiece {
public:
    CPiece();
    CPiece(COLOR color);
    CPiece(const CPiece& orig);
    virtual ~CPiece();
    
    bool takePiece() const;    
    
    void printPiece() const;
    //virtual bool isLegalMove(int x, int y) const = 0;
    
    FIGURENAME getName() const;
    COLOR getColor() const;
    int getX() const;
    int getY() const;
    virtual MoveList & getLegalMoves(const CBoard &  board) = 0;
    
    bool isFriendPiece(CPiece * tmp) const;
    virtual int checkField(int x,int y, const CBoard & board);
    
    
    //CPiece * getPieceByLetter(char letter);
    
    //void acceptVisitor(const CVisitor & v) const;
    
    //CPiece & operator=(const CPiece & oth); // ?? reference na CPiece
    
    bool isLongRunner;
    MoveList moveList;
    
protected:
    
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

