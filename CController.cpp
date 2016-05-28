#include "CController.h"
#include "CMainMenu.h"
#include "CDifficultyMenu.h"
#include "CColorMenu.h"
#include "CGUI.h"

CController::CController(){
    
    menu = new CMainMenu();
    
}

void CController::deleteMenus(){
        
    CAbstractMenuScreen * tmp = menu;
    CAbstractMenuScreen * tmp2 = tmp;
    
    if(menu == NULL)    // vse uz je smazano (treba proto ze jsem BACKoval zpatky v menu)
        return;
    
    while(tmp->prevMenu != NULL)    //dojedu na zacatek spojaku menus
        tmp = tmp->prevMenu;
    
    while(tmp->nextMenu != NULL){   // mazu od zacatku do konce
        
        tmp = tmp->nextMenu;
        delete tmp2;
        tmp2 = tmp;
    }
    
    delete tmp;
}


CController::~CController(){
    
    deleteMenus();
}

void CController::showMenus(){    
        
    while(menu != NULL){
        menu->show();
        cout << "vybrano: "<< menu->readInput()<<endl;
        menu->setStuff(this);
        menu->setNextMenu();
        
        menu = menu -> nextMenu;
        
    }
        
}

void CController::startGame(){
    game.start();
}

void CController::printBoard() const{
    
    gui.printBoard(game.getBoard());
}

CGameSession& CController::getGameSess() {
    return game;
}
