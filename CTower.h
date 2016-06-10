#ifndef CTOWER_H
#define	CTOWER_H

#include "COLOR.h"
#include "CPiece.h"

class CTower : public CPiece{
public:
    CTower();
        /**
     * Initiates a tower with given parameters
     * @param color A color of the tower
     * @param row A row of the tower on a chessboard
     * @param col A column of the tower on a chessboard
     */ 
    CTower(COLOR col,int x, int y);
    virtual ~CTower();
    /**
     *  Checks available moves for this tower
     * @param gS Reference to the instance of a game
     * @return Reference to a list of all possible moves of this tower
     */
    virtual MoveList & getLegalMoves(const CGameSession & gS);
     /**
     *  Copies an instance of the tower
     * @param pcs a pointer to the tower, to be copied
     * @return a new instance of this tower
     */
    virtual CPiece* copyPiece(const CPiece * pcs) const;

};



#endif	/* CTOWER_H */

