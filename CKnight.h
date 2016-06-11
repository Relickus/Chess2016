#ifndef CKNIGHT_H
#define	CKNIGHT_H

#include "CPiece.h"
#include "COLOR.h"

/**
 * Class representing knight piece
 */
class CKnight : public CPiece{
public:
    CKnight();
        /**
     * Initiates a knight with given parameters
     * @param color A color of the knight
     * @param row A row of the knight on a chessboard
     * @param col A column of the knight on a chessboard
     */
    CKnight(COLOR col , int x, int y);
    virtual ~CKnight();
    /**
     *  Checks available moves for this knight
     * @param gS Reference to the instance of a game
     * @return Reference to a list of all possible moves of this knight
     */
    virtual CMoveList & getLegalMoves(const CGameSession & gS);
        /**
     *  Copies an instance of the knight
     * @param pcs a pointer to the knight, to be copied
     * @return a new instance of this knight
     */
    virtual CPiece* copyPiece(const CPiece * pcs) const;

};



#endif	/* CKNIGHT_H */

