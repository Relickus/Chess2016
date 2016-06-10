#ifndef CKING_H
#define	CKING_H

#include "CPiece.h"
#include "COLOR.h"

class CGameSession;

/**
 * Class representing king piece
 */
class CKing : public CPiece{
public:
    CKing();
        /**
     * Initiates a king with given parameters
     * @param color A color of the king
     * @param row A row of the king on a chessboard
     * @param col A column of the king on a chessboard
     */
    CKing(COLOR col , int x, int y);
    virtual ~CKing();
    
    bool isChecked(const CBoard & board,bool currentPlayerDown) const;
    /**
     *  Checks available moves for the king
     * @param gS Reference to the instance of a game
     * @return Reference to a list of all possible moves of the king
     */
    virtual MoveList & getLegalMoves(const CGameSession & gS);
     /**
     *  Checks if the king can move to given field
     * @param row a row of the new field
     * @param col a column of the new field 
     * @param board reference to the instance of a chessboard
     * @return 0 for positive answer, 1 for negative
     */
    virtual int checkField(int x, int y, const CBoard& board);

        /**
     *  Copies an instance of the king
     * @param pcs a pointer to the king, to be copied
     * @return a new instance of the king
     */
    virtual CPiece* copyPiece(const CPiece* pcs) const ;

};



#endif	/* CKING_H */

