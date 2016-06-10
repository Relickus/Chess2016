#ifndef CQUEEN_H
#define	CQUEEN_H

#include "CPiece.h"
#include "COLOR.h"

/**
 * Class representing queen piece
 */
class CQueen : public CPiece {
public:
    CQueen();
        /**
     * Initiates a queen with given parameters
     * @param color A color of the queen
     * @param row A row of the queen on a chessboard
     * @param col A column of the queen on a chessboard
     */ 
    CQueen(COLOR col,int x, int y);
    virtual ~CQueen();
    /**
     *  Checks available moves for this queen
     * @param gS Reference to the instance of a game
     * @return Reference to a list of all possible moves of this queen
     */
    virtual MoveList & getLegalMoves(const CGameSession & gS);
        /**
     *  Copies an instance of the queen
     * @param pcs a pointer to the queen, to be copied
     * @return a new instance of this queen
     */
    virtual CPiece* copyPiece(const CPiece * pcs) const;

};



#endif	/* CQUEEN_H */

