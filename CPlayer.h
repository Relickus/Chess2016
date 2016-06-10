#ifndef COPPONENT_H
#define	COPPONENT_H

#include "COLOR.h"
#include "MoveList.h"
#include <vector>

using namespace std;

class CCommand;
class CGameSession;
class CPiece;
class CKing;
class CBoard;

class CPlayer {
public:
    CPlayer();
    virtual ~CPlayer();
    /**
     * abstract method to get move from player
     * @param gS reference to instance of a game
     * @param cliSocket Socket to read move from
     * @return Move received from player
     */
    //virtual MyMove getMove(const CGameSession & gS,int cliSocket=-1) = 0;
    /**
     * Returns this player's color
     * @return Color of the player
     */
    COLOR getPlayerColor() const;
    /**
     * Prints player's color into given ostream
     * @param os ostream to print into
     */
    void printPlayerColor(ostream & os) const;
    /**
     * Sets color to this player
     * @param col Color to be set
     */
    void setPlayerColor(COLOR col);
    /**
     * Finds all figures of this player
     * @param board reference to a chessboard
     */
    void findAllFigures(const CBoard & board);
    
    /**
     * gets command from user
     * @param gS reference to instance of a game
     * @return command received from user
     */
    virtual CCommand getCommand(const CGameSession & gS) = 0;
    /**
     * Checks whether this player's king is in check
     * @param gS reference to instance of a game
     */
    bool kingIsChecked(const CGameSession & gS) const;
    /**
     * Sets given king to this player
     * @param k king to be set
     */
    void setKing(CKing * k);
    
    /**
     *returns this player's socket
     */
    virtual int getSocket() const;
    
//protected: 
    
    COLOR playerColor;  ///< color of the player
    vector<CPiece*>figuresVec;      ///< vector of all figures belonging to this user
    MoveList allMoves;  ///< All possible moves to be done by the player
    CKing * playersKing;    ///< pointer to player's king
    
    friend CGameSession;
};




#endif	/* COPPONENT_H */

