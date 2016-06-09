
#include <unistd.h>

#include "CHostJoinMenu.h"
#include "CColorMenu.h"
#include "CController.h"
#include "CLocalPlayer.h"
#include "CRemotePlayer.h"

#define OPT_HOST 1
#define OPT_JOIN 2
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
            
        case(OPT_HOST):
           //nextMenu = new CColorMenu(this);  
            nextMenu = NULL;
            break;
            
        case(OPT_JOIN):
            //nextMenu = new CMultiplayerJoinMenu(this);  
            nextMenu = NULL;
            break;
                        
    }
    
}

CHostJoinMenu::~CHostJoinMenu(){
    
}

void CHostJoinMenu::setStuff(CController* ctrler) {
 
    int sock = -1;
    int ret;
    COLOR col;
    
    switch(chosenOption){
        
     //---------------server cast----------------
        
        case(OPT_HOST) :  
            
            ret = ctrler->startServer();
               if(ret == -1){
                   cout<<"SERVER SE NEPODARILO SPUSTIT!"<<endl;
                   ctrler->endGame();
                   return;
               }
               // pote co skonci server na signal
        ctrler->endGame();
        return;
     //---------------------------------------------------------  

        case(OPT_JOIN) :
            delete ctrler->getGameSess().player1;
            delete ctrler->getGameSess().player2;
            ctrler->getGameSess().netGameInit();
            
         break;  
       default:
           cout<<"nevalidni moznost v hostjoinmenu"<<endl;
           break;
             
    }
    
}
