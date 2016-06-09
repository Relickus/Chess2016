#ifndef CCOMMAND_H
#define	CCOMMAND_H

#include "COMMAND.h"
#include "MyMove.h"
#include "CController.h"

class CGameSession;

using namespace std;

/**
 * Class representing a command that can be executed
 * A command can be anything from @ref ENUM_COMMAND enum
 */
class CCommand {
public:
    CCommand();
    /**
     * Construct CComand from MyMove
     * @param mv
     */
    CCommand(const MyMove & mv);
    /**
     * Copyconstructor
     * @param com copied CComand
     */
    CCommand(COMMAND com);
    
    /**
     * Creates command from user input
     * @param str user input
     */
    void makeCommand(const string & str);
    /**
     * Executes command specified by @ref ENUM_COMMAND inside command
     * @param gS reference to instance of the game
     */
    void executeCommand(CGameSession & gS);

    /**
     * Performs move stored in command
     * @param gS reference to instance of the game
     */
    void movesQuery(CGameSession & gS) const;
        
    /**
     * Exit game call
     * @param gS reference to instance of the game
     */
    void exitQuery(CGameSession & gS) const;
       
    /**
     * Savegame call.
     * @param gS reference to instance of the game
     */
    void saveQuery(CGameSession & gS) const;
    /**
     * Rotates the chessboard.
     * @param gS reference to instance of the game
     */
    void rotateQuery(const CGameSession & gS) const;
        
    /**
     * Performs a move stored in move variable.
     * @param gS reference to instance of the game
     */
    void makeMoveQuery(CGameSession & gS) const;  
    /**
     * Checkmate reached - call for surrender of the caller .
     * @param gS reference to instance of the game
     */
    void surrenderQuery(CGameSession & gS) const;
    /**
     * Informs players about occured check.
     * @param gS reference to instance of the game
     */
    void checkQuery(CGameSession & gS) const;
    /**
     * Informs players about a tie. Then ends the game.
     * @param gS reference to instance of the game
     */
    void tieQuery(CGameSession & gS) const;
    /**
     * Returns reference to the move stored in the command
     * @return stored move
     */
    const MyMove & getMoveRef() const;
    
    COMMAND command;    ///< type of command - see @ref ENUM_COMMAND
    
private:
    int x;
    int y;
    MyMove move; ///< Move to be executed if MAKEMOVE is selected
    
    friend CController;
    
};



#endif	/* CCOMMAND_H */

