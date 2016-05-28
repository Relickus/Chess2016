#include "CColorMenu.h"
#include "CAbstractMenuScreen.h"
#include "CGameSession.h"
#include "CController.h"

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
        case(3) : 
            nextMenu = prevMenu;
            break;
            
        default : 
            nextMenu = NULL;    // toto je momentalne posledni menu
            break;
    }
    
}

void CColorMenu::setStuff(CController* ctrler) {

    ctrler -> getGameSess().player1color = (chosenOption == 1 ? WHITE : BLACK);
    
}
