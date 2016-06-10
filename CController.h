#ifndef CCONTROLLER_H
#define	CCONTROLLER_H

#include "COLOR.h"
#include "CGameSession.h"
class CAbstractMenuScreen;

/**
 * 
 * Class performing high-level functionality (should resemble a controller as in the MVC design pattern)
 */
class CController {
public:
    CController();
    /**
     *  Calls for a deletion of menu screens
     */
    virtual ~CController();
    /**
     *  Calls a current menu to display itself
     */
    void showMenus();
    /**
     *  Calls for a game initalization
     */
    void startGame();
        /**
     *  Calls for a game termination
     */
    void endGame();
     /**
     *  Returns a reference to the instance of a game
     */
    CGameSession & getGameSess();
        /**
     *  The main game loop where everything happens
     */
    void gameLoop();
     /**
     *  Calls initialization of a game server (online play only)
     */
    
private:
    /**
     *  Deletes a linked list of menu screens
     */
    void deleteMenus();

    CAbstractMenuScreen * menu; ///< The head of the linked list of menu screens
    CGameSession game;  ///< the instance of a game containing all important data and functionality
    //CGUI gui;
};

#endif	/* CCONTROLLER_H */

