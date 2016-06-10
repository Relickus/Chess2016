#ifndef CBISHOP_H
#define	CBISHOP_H

#include "CPiece.h"
#include "COLOR.h"

/**
 * Class representing bishop piece
 */
class CBishop : public CPiece {
public:
    CBishop();
        /**
     * Initiates a bishop with given parameters
     * @param color A color of the bishop
     * @param row A row of the bishop on a chessboard
     * @param col A column of the bishop on a chessboard
     */
    CBishop(COLOR col , int x, int y);
    virtual ~CBishop();
    /**
     *  Checks available moves for this bishop
     * @param gS Reference to the instance of a game
     * @return Reference to a list of all possible moves of this bishop
     */
    virtual MoveList & getLegalMoves(const CGameSession & gS);
     /**
     *  Copies an instance of the bishop
     * @param pcs a pointer to the bishop, to be copied
     * @return a new instance of this bishop
     */
    virtual CPiece* copyPiece(const CPiece* pcs) const ;


};



#endif	/* CBISHOP_H */

