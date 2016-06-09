#ifndef CPIECE_H
#define	CPIECE_H

#include "COLOR.h"
#include "FIGURENAME.h"
#include "MoveList.h"

#include <iostream>

class CBoard;
class CGameSession;
class MyMove;

class CPiece {
public:
    
    static CPiece * getPieceByLetter(char c, int row, int col);
    static bool validLetter(char c); 
    
    CPiece();
    CPiece(COLOR color,int row, int col);
    virtual ~CPiece();
    
    bool takePiece() const;    
    
    void printPiece(ostream & os) const;
    //virtual bool isLegalMove(int x, int y) const = 0;
    
    FIGURENAME getName() const;
    COLOR getColor() const;
    int getRow() const;
    int getCol() const;
    int getValue() const;
    
    void setRow(int r);
    void setCol(int c);
    
    virtual MoveList & getLegalMoves(const CGameSession & gS) = 0;
    bool equals(FIGURENAME fig) const;
    
    bool isFriendPiece(const CPiece * tmp) const;
    bool isFriendPiece(COLOR col) const;
    virtual int checkField(int row, int col, const CBoard & board);
    bool moveTo(const MyMove & move, CBoard & board );    
    virtual CPiece * copyPiece(const CPiece * pcs) const = 0;
    
    MoveList moveList;
    
protected:

    int rowPos;
    int colPos;
    COLOR color;
    FIGURENAME name;
    int value;
    
};


#endif	/* CPIECE_H */

