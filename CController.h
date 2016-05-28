#ifndef CCONTROLLER_H
#define	CCONTROLLER_H

#include "CAbstractMenuScreen.h"
#include "CGameSession.h"
#include "CGUI.h"


class CController {
public:
    CController();
    CController(const CController& orig);
    virtual ~CController();
    
    void showMenus();
    void printBoard() const;
    void startGame();
    CGameSession & getGameSess();
    
private:
    void deleteMenus();

    CAbstractMenuScreen * menu;
    CGameSession game;
    CGUI gui;
    
};

#endif	/* CCONTROLLER_H */

