
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
 
    int ret;
    CServer server;
    
    switch(chosenOption){
        
     //---------------server cast----------------
        
        case(OPT_HOST) :  
            
            ret = server.startServer();
               if(ret == -1){
                   cout<<"Server se nepodařilo spustit."<<endl;
                   ctrler->endGame();
                   return;
               }
               // pote co skonci server
        ctrler->endGame();
        return;
     //---------------------------------------------------------  

        case(OPT_JOIN) :
            delete ctrler->getGameSess().player1;
            delete ctrler->getGameSess().player2;
            ctrler->getGameSess().netGameInit();
            
         break;  
       default:
           cout<<"Nevalidní možnost menu."<<endl;
           break;
             
    }
    
}
