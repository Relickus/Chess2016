
#include "CMainMenu.h"
#include "COpponentMenu.h"
#include "CLoadGameMenu.h"


CMainMenu::CMainMenu(CAbstractMenuScreen * prPar /* =NULL*/) : CAbstractMenuScreen(prPar){
    
    title = "Vyberte herni mod:";
    
    menuItems[0] = "New game";
    menuItems[1] = "Load game";
    menuItems[2] = "Exit";
    
    setNumMenuItems();
}

CMainMenu::~CMainMenu(){
    
}

void CMainMenu::setNextMenu() {
    
        delete nextMenu;
        
    switch(chosenOption){
        
        case(1) : 
            nextMenu = new COpponentMenu(this);
            break;
        
        case(2) : 
            nextMenu = new CLoadGameMenu(this);
            break;
        
        case(3) : 
            nextMenu = NULL;
            break;
            
    }
    
    
}

void CMainMenu::setStuff(CController* ctrler) {

}
