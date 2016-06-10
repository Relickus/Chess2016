#ifndef CINTELLIGENCE_H
#define	CINTELLIGENCE_H

#include "DIFFICULTY.h"

#include "CPlayer.h"

/**
 * Subclass of CPlayer representing AI
 */
class CIntelligence : public CPlayer {
public:
    CIntelligence();
    /**
     * 
     * @param d A desired level of difficulty
     */
    CIntelligence(int d);
    /**
     * @brief Change the difficulty level
     * @param d New difficulty level
     */
    void changeDifficulty(int d);
    /**
     * @brief Gets move from AI
     * @param gS reference to instance of the game
     * @param cliSocket socket to be read from
     * @return Received move
     */
    virtual MyMove getMove(const CGameSession & gS,int cliSocket=-1);
    /**
     * @brief Gets command from AI
     * @param gS reference to instance of the game
     * @return Received command
     */
    virtual CCommand getCommand(const CGameSession & gS);

    
private:
    
    /**
     * @brief Gets index of the best move in the list of possible moves 
     * @param list reference to the list of moves
     * @param board reference to the chessboard
     * @return index of the best move in list of moves
     */
    int getBestIdx(MoveList & list,const CBoard & board) const;
    /**
     * @brief Removes all faulty (check) moves from the list of all possible moves
     * @param list reference to list moves
     * @param board reference to the chessboard
     */
    void eraseCheckMoves(MoveList & l, const CGameSession & gS);
    
    
    int difficulty; ///< The difficulty level
};




#endif	/* CINTELLIGENCE_H */

