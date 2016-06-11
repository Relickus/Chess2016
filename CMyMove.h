#ifndef MOVE_H
#define	MOVE_H

#include <iostream>

using namespace std;

class CPiece;

/**
 * Class representing a move from one slot to another 
 */
class CMyMove{
    
public:
    
    CMyMove();
    /**
     * Copyconstructor
     * @param oth An instance of a move to be copied
     */
    CMyMove(const CMyMove & oth);
    /**
     * Creates a move from string
     * @param movestr String s tahem
     */
    CMyMove(const string & movestr);
    /**
     * Creates a move from cstring
     * @param buffer Array with cstringe reprezenting the move
     */
    CMyMove(const char * buffer);
    bool operator==(const CMyMove & oth) const;
    /**
     *  
     * @param tX A destination row 
     * @param tY A destination column 
     * @param frX An origin row 
     * @param frY An origin column
     * @param tmp A figure taken by the move
     */
    CMyMove(int tX, int tY,int frX=-1,int frY=-1,CPiece * tmp=NULL);       // POZOR, nejdrive TO , pak FROM souradnice
    /**
     * Recalculates received move to a move from the other side of a chessboard
     */
    void rotateMove();
    /**
     * Prints a move
     */
    void printMove() const;
    /**
     * Checks whether the move is a ficture move
     * Ficture is a special instance of the move (dummy object), used in places where code needs it
     */
    bool isFicture() const;
    /**
     * Transforms the move to a c string
     * @param[in,out] buffer Array to be filled with the result cstring
     */
    void tocstring(char * buffer) const;
    
    
    int fromX;  ///< An origin row 
    int fromY;  ///< An origin colum 
    int toX;    ///< A destination row 
    int toY;    ///< A destination column 
    CPiece * figure;    ///< A figure sebraná tahem
};


#endif	/* MOVE_H */

