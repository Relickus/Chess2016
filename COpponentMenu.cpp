
#include "COpponentMenu.h"
#include "CMultiplayerJoinMenu.h"
#include "CMultiplayerLocalMenu.h"
#include "CDifficultyMenu.h"
#include "CColorMenu.h"
#include "CController.h"
#include "CIntelligence.h"
#include "CLocalPlayer.h"
#include "CRemotePlayer.h"

#define OPT_BACK 5

COpponentMenu::COpponentMenu(CAbstractMenuScreen * prPar /* =NULL*/) : CAbstractMenuScreen(prPar){
    
    title = "Vyberte protivnika:";
    
    menuItems[0] = "Singleplayer game";
    menuItems[1] = "Local Multiplayer game";
    menuItems[2] = "Online multiplayer game";
    menuItems[3] = "AI vs. AI";
    menuItems[4] = "BACK";
    
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
            nextMenu = new CMultiplayerJoinMenu(this);
            break;
        
        case(4):
            nextMenu = NULL;
            break;
        case(OPT_BACK) : 
            nextMenu = prevMenu;
            break;
    }    
}

void COpponentMenu::setStuff(CController* ctrler) {

    delete  ctrler->getGameSess().player1;
    ctrler->getGameSess().player1 = new CLocalPlayer();
    
    switch(chosenOption){
        
        case(1):
            delete ctrler->getGameSess().player2;
            ctrler->getGameSess().player2 = new CIntelligence();
            break;
        case(2):
            delete ctrler->getGameSess().player2;
            ctrler->getGameSess().player2 = new CLocalPlayer();        
            break;
        case(3):
             delete ctrler->getGameSess().player2;
             ctrler->getGameSess().player2 = new CRemotePlayer();   
             break;
        case(4):
             delete ctrler->getGameSess().player1;
             delete ctrler->getGameSess().player2;
             ctrler->getGameSess().player1 = new CIntelligence(0);   
             ctrler->getGameSess().player2 = new CIntelligence(0);  
             
             ctrler -> getGameSess().setPlayerColors(WHITE);
             ctrler->getGameSess().setGameReady();
             break;
    }
    // cntr-> get game session . opponent = tmpoponent
}
