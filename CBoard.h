#ifndef CBOARD_H
#define	CBOARD_H
#include "COLOR.h"
#include "CSlot.h"

class CGameSession;
class CPiece;
class CKing;
class CSlot;
class MoveList;
class MyMove;

using namespace std;

/**
 * Class representing a chessboard
 */
class CBoard {
    
    /**
     * Static method rotating given move as if it was made from the other side of the board
     * @param MyMove given move to rotate
     */
    static void translateMove(MyMove & move);
    
public:
    CBoard();
    /**
     * Copyconstructor
     * @param oth Another board
     */
    CBoard(const CBoard & oth);
    /**
     * Like copyconstructor but performed on existing board
     * @param oth Another board
     */
    void copy(const CBoard & oth);
    
    /**
     * Prints the board and its pieces in a fancy way (obviously)
     */
    void printBoard() const;
    
    /**
     * (DEV FEATURE) Prints information about all slots on the board
     */
    void printDebug() const;
    
    /**
     * Prints rotated board. Used for a 'rotate' command from user - see @ref COMMAND
     */
    void printRotate() const;
    /**
     *  (DEV FEATURE) Prints all possible moves that have been found for current player
     * @param list List of the moves
     */
    void printPossibleMoves(const MoveList & list) const;
    
    /**
     * Fills the chessboard with pieces
     * @param gameSess pointer to instance of the game
     */
    void initBoard(const CGameSession * gameSess);    
    
    /**
     * Returns a piece stored on a given slot
     * @param x Row of the slot
     * @param y Column of the slot
     * @return pointer to the stored piece
     */
    CPiece * getPiece(int x, int y) const;
    /**
     * Checks whether a slot is in or out of the chessboard
     * @param x Row of the slot
     * @param y Column of the slot
     */
    bool outOfBoard(int x,int y) const;
    /**
     * Sets a given piece to a given slot on the chessboard
     * @param row Row of the slot
     * @param col Column of the slot
     * @param pc Pointer to the piece to be set
     */
    void setField(int row, int col, CPiece * pc);    
    /**
     * Actually rotates the board
     */
    void rotateBoard();
    /**
     * Performs a move given by a parameter
     * @param move Move to be performed
     */
    void moveFigure(const MyMove & move);
    /**
     * Returns a value of a given slot on the chessboard
     * @param x Row of the slot 
     * @param y Column of the slot
     * @return Value of the slot
     */
    int getSlotValue(int x,int y) const;
    /**
     * Creates a ficture chessboard and performs a given move on it
     * @param move Move to be performed
     * @param gS reference to the game instance
     * @return bool Indicator if the move is valid (Not resulting with a check of the current player's king)
     */
    bool tryMove(const MyMove & move,const CGameSession & gS) const;
    /**
     * Finds a king specified by a its color on the chessboard
     * @param col Color of the king to be found
     * @return pointer to the king of the given color (the king certainly exists)
     */
    CKing * findKing(COLOR col) const;

    
    int INIT_ROW_UP;    ///< The starting row of the pawns on the upper side of the board
    int INIT_ROW_DOWN;  ///< The starting row of the pawns on the lower side of the board

    int LAST_ROW_UP;    ///< The last row on the upper side of the board
    int LAST_ROW_DOWN;  ///< The last row on the lower side of the board
    
private:
    
    /**
     * Swaps figures on two slots
     * @param r1 Row of the first slot
     * @param c1 Column of the first slot
     * @param r2 Row of the second slot
     * @param c2 Column of the second slot
     */
    void swapFigures(int r1,int c1, int r2,int c2);
    /**
     * Creates pieces. Called by CBoard::initBoard() method
     * @param colorUp A color of the figures on the upper side of the board
     */
    void createPieces(COLOR colorUp);
    /**
     * When a pawn reaches the other side of the board it gets exchanged for a queen figure
     * @param move The move of a pawn to the edge of the board
     */
    void promotePawn(const MyMove & move);
    
    CSlot slotsArr[8][8];   ///< 2D array of the slots holding the figures
    const int width;
    const int height;
    
    
};


#endif	/* CBOARD_H */

