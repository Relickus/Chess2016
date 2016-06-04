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
    CPiece(COLOR color,int row, int col);
    CPiece(const CPiece& orig);
    virtual ~CPiece();
    
    bool takePiece() const;    
    
    void printPiece() const;
    //virtual bool isLegalMove(int x, int y) const = 0;
    
    FIGURENAME getName() const;
    COLOR getColor() const;
    int getRow() const;
    int getCol() const;
    
    void setRow(int r);
    void setCol(int c);
    
    virtual MoveList & getLegalMoves(const CBoard &  board) = 0;
    bool equals(FIGURENAME fig) const;
    
    bool isFriendPiece(const CPiece * tmp) const;
    bool isFriendPiece(COLOR col) const;
    virtual int checkField(int row,int col, const CBoard & board);
    
    static CPiece * getPieceByLetter(char c, int row, int col);
    static bool validLetter(char c); 
    bool moveTo(const MyMove & move, CBoard & board );    
    int getValue() const;
    
    
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

    int rowPos;
    int colPos;
    COLOR color;
    FIGURENAME name;
    int value;
    
};


#endif	/* CPIECE_H */

