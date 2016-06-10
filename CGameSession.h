#ifndef CGAMESESSION_H
#define	CGAMESESSION_H

#include "COLOR.h"
#include <iostream>
#include "CBoard.h"
#include "CNetworking.h"
#include "CServer.h"

class CPersistence;
class CPlayer;

using namespace std;

/**
 * A crossroad class containg all importand game data and performing all game related operations
 */
class CGameSession {
public:
    /**
     * Checks whether a given move is in a correct format and if it is withing a chessboard
     * @param move Given move
     */
    static bool validateMove(const string & move);
    /**
     * Checks whether a position in the given move is in a chessboard
     * @param move Move containing the checked position
     */
    static bool validatePos(const string & move);
    
    CGameSession();
    ~CGameSession();
    
    /**
     * Starts the game (initiates a chessboard and assigns kings)
     */
    void start();
    /**
     * Ends the game (deletes dynamic data structures)
     */
    void end();
    
    /**
     * A board getter
     * @return A constant reference to the board instance
     */
    const CBoard & getBoard() const;
    /**
     * Sets a flag 
     */
    void setGameReady();
    /**
     * Checks whether the game is ready to be started
     */
    bool gameReady() const;
    /**
     * Assigns colors to both players. Given color is a color of player 1.
     * @param col A color of player 1.
     */
    void setPlayerColors(COLOR col);
    /**
     * Sets a variable to keep a track of whos turn is it
     * @param col Color of the player currently in turn
     */
    void setTurn(COLOR col);
    /**
     * Performs a move on the chessboard
     * @param move A move to be performed
     * @return Success or failure of the operation
     */
    bool performMove(const MyMove & move);
    /**
     * Switches current player pointer to the other player. Used in game loop.
     */
    void switchPlayers();
    /**
     * Checks whether the current player's king is checked.
     */
    bool isCheckMate() const;
    /**
     * Finds both players' kings and assigns them to players
     */
    void assignKings();
    //void updateKings();
    /**
     * Checks whether the game has come to a tie (only both kings left on the chessboard)
     * @return 
     */
    bool isTie() const;
    /**
     * Initializes an online game data
     */
    void netGameInit();

    
    string fileName;        ///< name of the loaded file
    
    bool ready_flag;        
    bool exitRequest;       
    bool onlineGame;
    bool movePerformed;     
    
    COLOR whosTurn;
    COLOR currentPlayer;    ///< Current player's color
    
    CPlayer * player1;      ///< A pointer to player 1
    CPlayer * player2;      ///< A pointer to player 2
    CPlayer * currPlayerPtr;    ///< A pointer to either player 1 or player 2
    CPersistence * persistence; ///< A pointer to class executing save/load operations
    
    CNetworking networking;     ///< A class performing client network operations
    
private:       
    CBoard gameBoard;       ///< The chessboard
    
   friend class CLoadGameMenu; 
    
};



#endif	/* CGAMESESSION_H */

