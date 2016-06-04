
#include "CMainMenu.h"
#include "COpponentMenu.h"
#include "CLoadGameMenu.h"
#include "CController.h"

#define OPT_NEW 1
#define OPT_LOAD 2
#define OPT_EXIT 3


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
        
        case(OPT_NEW) : 
            nextMenu = new COpponentMenu(this);
            break;
        
        case(OPT_LOAD) : 
            nextMenu = new CLoadGameMenu(this);
            break;
        
        case(OPT_EXIT) : 
            nextMenu = NULL;
            break;
            
    }
    
    
}

void CMainMenu::setStuff(CController* ctrler) {
    
    
}
