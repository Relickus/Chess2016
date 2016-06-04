
#include "CHostJoinMenu.h"
#include "CMultiplayerJoinMenu.h"
#include "CMultiplayerHostMenu.h"

CHostJoinMenu::CHostJoinMenu(CAbstractMenuScreen* prPar){
    
    title = "Zalozit server nebo se pripojit?";
    
    menuItems[0] = "Host";
    menuItems[1] = "Join";
    menuItems[2] = "BACK";    
    
    prevMenu = prPar;
    
    setNumMenuItems();
    
}

void CHostJoinMenu::setNextMenu() {

    delete nextMenu;
    
    switch(chosenOption){
        case(3) : 
            nextMenu = prevMenu;
            break;            
            
        case(1):
           nextMenu = new CMultiplayerHostMenu(this);  
            break;
            
        case(2):
            nextMenu = new CMultiplayerJoinMenu(this);  
            break;
                        
    }
    
}

CHostJoinMenu::~CHostJoinMenu(){
    
}

void CHostJoinMenu::setStuff(CController* ctrler) {

}
