
#include "CHostJoinMenu.h"
#include "CMultiplayerJoinMenu.h"
#include "CMultiplayerHostMenu.h"
#include "CColorMenu.h"
#include "CController.h"
#include "CLocalPlayer.h"
#include "CRemotePlayer.h"

#define OPT_BACK 3

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
        case(OPT_BACK) : 
            nextMenu = prevMenu;
            break;            
            
        case(1):
           nextMenu = new CColorMenu(this);  
            break;
            
        case(2):
            nextMenu = new CMultiplayerJoinMenu(this);  
            break;
                        
    }
    
}

CHostJoinMenu::~CHostJoinMenu(){
    
}

void CHostJoinMenu::setStuff(CController* ctrler) {

     delete ctrler->getGameSess().player1;
     delete ctrler->getGameSess().player2;

     switch(chosenOption){
        case(0) : 
            ctrler->getGameSess().player1 = new CLocalPlayer();
            ctrler->getGameSess().player2 = new CRemotePlayer();
          break;
        case(1) :
            ctrler->getGameSess().player1 = new CLocalPlayer();
            ctrler->getGameSess().player2 = new CRemotePlayer();
            
//            if( net.startServer() == -1){
//                
//            }
//            
         break;  
       default:
           break;
             
    }
    
}
