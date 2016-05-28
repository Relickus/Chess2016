
#include "COpponentMenu.h"
#include "CMultiplayerOnlineMenu.h"
#include "CMultiplayerLocalMenu.h"
#include "CDifficultyMenu.h"
#include "CColorMenu.h"

COpponentMenu::COpponentMenu(CAbstractMenuScreen * prPar /* =NULL*/) : CAbstractMenuScreen(prPar){
    
    title = "Vyberte protivnika:";
    
    menuItems[0] = "Singleplayer game";
    menuItems[1] = "Local Multiplayer game";
    menuItems[2] = "Online multiplayer game";
    menuItems[3] = "BACK";
    
    setNumMenuItems();
}

COpponentMenu::~COpponentMenu() {

}


void COpponentMenu::setNextMenu(){
    
    delete nextMenu;

    switch(chosenOption){
        
        case(1) : 
            nextMenu = new CDifficultyMenu(this);
            break;
            
        case(2) : 
            nextMenu = new CColorMenu(this);
            break;
            
        case(3) : 
            nextMenu = new CMultiplayerOnlineMenu(this);
            break;
        
        case(4) : 
            nextMenu = prevMenu;
            break;
    }    
}

COpponent* COpponentMenu::getOpponent() const {

    
    
}

void COpponentMenu::setStuff(CController* ctrler) {

}
