#include "CDifficultyMenu.h"
#include "CColorMenu.h"
#include "CController.h"
#include "CIntelligence.h"

CDifficultyMenu::CDifficultyMenu(CAbstractMenuScreen * prPar /* =NULL*/) : CAbstractMenuScreen(prPar) {
    
    menuItems[0] = "Easy";
    menuItems[1] = "Medium";
    menuItems[2] = "Hard";
    menuItems[3] = "BACK";
    
    title = "Zvolte obtížnost hry proti PC:";
    
    setNumMenuItems();
    
}

CDifficultyMenu::~CDifficultyMenu(){
    
}

void CDifficultyMenu::setNextMenu() {
   
    delete nextMenu;
        
    switch(chosenOption){
        
        case(5):
            nextMenu = prevMenu;
            break;
            
        default:
            nextMenu = new CColorMenu(this);
            break;
    }
}

void CDifficultyMenu::setStuff(CController* ctrler) {

    if(chosenOption != 4){
        CIntelligence * tmp = dynamic_cast<CIntelligence*>(ctrler->getGameSess().player2);
        tmp->changeDifficulty(chosenOption-1);
    }
    
}
