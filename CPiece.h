#ifndef CPIECE_H
#define	CPIECE_H

#include "COLOR.h"
#include "FIGURENAME.h"
#include "MoveList.h"

#include <iostream>

class CBoard;
class CGameSession;
class MyMove;

/**
 * 
 * Parent class for a piece
 * 
 */
class CPiece {
public:
    
    /**
     * 
     * @param c A letter identifying a piece
     * @param row A row of origin of a piece
     * @param col A column  of origin of the piece
     * @return Pointer to a piece on a chessboard
     */
    static CPiece * getPieceByLetter(char c, int row, int col);
    
    /**
     * Checks whether a given letter is a valid piece letter
     * @param c letter to be checked
     */
    static bool validLetter(char c); 
    
    CPiece();
    /**
     * Initiates a piece with given parameters
     * @param color A color of the piece
     * @param row A row of the piece on a chessboard
     * @param col A column of the piece on a chessboard
     */
    CPiece(COLOR color,int row, int col);
    
    virtual ~CPiece();
    
    /**
     *  Prints out the piece into a given ostream
     * 
     * @param os Ostream to be written into
     */
    void printPiece(ostream & os) const;
    
    /**
     *  Returns a name of a piece
     * @return enum FIGURNAME indentifying the piece - see @ref ENUM_FIGURENAME
     */
    FIGURENAME getName() const;
     /**
     *  Returns a color of a piece
     * @return enum COLOR specifying a color of the piece
     */
    COLOR getColor() const;
     /**
     *  Returns a row of the piece
     * @return int a row of the piece
     */
    int getRow() const;
     /**
     *  Returns a column of the piece
     * @return int a colum n of the piece
     */
    int getCol() const;
    /**
     *  Returns a value of the piece
     * @return int a value of the piece
     */
    int getValue() const;
    
    /**
     *  Sets a value of the piece
     * @param val a value of the piece
     */
    void setValue(int val);
       
    /**
     *  Sets a row of the piece
     * @param r a row of the piece
     */
    void setRow(int r);
    /**
     *  Sets a column of the piece
     * @param c a column of the piece
     */
    void setCol(int c);
    
    /**
     *  Checks available moves for this piece
     * @param gS Reference to the instance of a game
     * @return Reference to a list of all possible moves of this piece
     */
    virtual MoveList & getLegalMoves(const CGameSession & gS) = 0;
    
    /**
     *  Checks if the piece equals another piece
     * @param fig A name of the piece
     */
    bool equals(FIGURENAME fig) const;
    
    /**
     *  Checks if a given piece is a friend piece
     * @param tmp a pointer to compared piece
     */
    bool isFriendPiece(const CPiece * tmp) const;
    /**
     *  Checks if the piece is the same color as parameter
     * @param col compared color 
     */
    bool isFriendPiece(COLOR col) const;
    /**
     *  Checks if the piece can move to given field
     * @param row a row of the new field
     * @param col a column of the new field 
     * @param board reference to the instance of a chessboard
     * @return 0 for positive answer, 1 for negative
     */
    virtual int checkField(int row, int col, const CBoard & board);
    /**
     *  Moves a piece to a given field
     * @param move Specifies coordinates of the move
     * @param board reference to the instance of a chessboard
     * @return if the move was successful
     */
    bool moveTo(const MyMove & move, CBoard & board );    
    /**
     *  Copies an instance of the piece
     * @param pcs a pointer to the piece, to be copied
     * @return a new instance of this piece
     */
    virtual CPiece * copyPiece(const CPiece * pcs) const = 0;
    
    MoveList moveList;  ///< An aid list of possible moves of this piece
    
protected:

    int rowPos; ///< A row of the piece
    int colPos; ///< A column of the piece
    COLOR color;    ///< A color of the piece
    FIGURENAME name;    ///< A name of the piece
    int value;  ///< A value of the piece
    
};


#endif	/* CPIECE_H */

