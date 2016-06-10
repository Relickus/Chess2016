#include "CColorMenu.h"
#include "CAbstractMenuScreen.h"
#include "CGameSession.h"
#include "CController.h"

#define OPT_BACK 3

CColorMenu::CColorMenu(CAbstractMenuScreen * prPar/* =NULL*/) : CAbstractMenuScreen(prPar) {
    
    title = "Zvolte barvu figurek hráče č.1:";
    
    menuItems[0] = "White";
    menuItems[1] = "Black";
    menuItems[2] = "BACK";    
    
    setNumMenuItems();
}

CColorMenu::~CColorMenu(){
    
}

void CColorMenu::setNextMenu() {

    delete nextMenu;
    
    switch(chosenOption){
        case(OPT_BACK) : 
            nextMenu = prevMenu;
            break;
            
        default : 
            nextMenu = NULL;    // toto je momentalne posledni menu
            break;
    }
    
}

void CColorMenu::setStuff(CController* ctrler) {

    if(nextMenu != NULL)
        return;
    
    if(chosenOption != 3){
        COLOR col = (chosenOption == 1 ? WHITE : BLACK);
        ctrler -> getGameSess().setPlayerColors(col);
        ctrler -> getGameSess().whosTurn = WHITE;
                
        ctrler -> getGameSess().setGameReady();
    }
}
