#ifndef CPAWN_H
#define	CPAWN_H

#include "CPiece.h"
#include "COLOR.h"

/**
 * Class representing pawn piece
 */
class CPawn : public CPiece{
public:
    CPawn();
        /**
     * Initiates a pawn with given parameters
     * @param color A color of the pawn
     * @param row A row of the pawn on a chessboard
     * @param col A column of the pawn on a chessboard
     */
    CPawn(COLOR col , int x, int y);
    virtual ~CPawn();

       
    /**
     *  Checks available moves for this pawn
     * @param gS Reference to the instance of a game
     * @return Reference to a list of all possible moves of this pawn
     */
    virtual MoveList & getLegalMoves(const CGameSession & gS);
    
    /**
     *An aid method called if the current pawn is going from the top to the bottom of the chessboard
     */
    MoveList & getLegalMovesUp(const CBoard &  board);
    /**
     *An aid method called if the current pawn is going from the bottom to the top of the chessboard
     */
    MoveList & getLegalMovesDown(const CBoard &  board);
    virtual int checkField(int x, int y, const CBoard& board, bool sidestep);

        /**
     *  Copies an instance of the pawn
     * @param pcs a pointer to the pawn, to be copied
     * @return a new instance of this pawn
     */
    virtual CPiece* copyPiece(const CPiece * pcs) const;

};



#endif	/* CPAWN_H */

