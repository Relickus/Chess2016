#ifndef CCONTROLLER_H
#define	CCONTROLLER_H

#include "COLOR.h"
#include "CGameSession.h"
#include "CGUI.h"
class CAbstractMenuScreen;


class CController {
public:
    CController();
    CController(const CController& orig);
    virtual ~CController();
    
    void showMenus();
    void printBoard() const;
    void startGame();
    void endGame();
    CGameSession & getGameSess();
    void gameLoop();
    int startServer();
    
private:
    void deleteMenus();

    CAbstractMenuScreen * menu;
    CGameSession game;
    CGUI gui;
    
};

#endif	/* CCONTROLLER_H */

