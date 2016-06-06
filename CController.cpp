#include "CController.h"
#include "CMainMenu.h"
#include "CDifficultyMenu.h"
#include "CColorMenu.h"
#include "CCommand.h"
#include "CPlayer.h"

#include "CAbstractMenuScreen.h"
#include "CGameSession.h"
#include "CGUI.h"

CController::CController(){
    
    menu = new CMainMenu();
    
}

void CController::deleteMenus(){
        
    CAbstractMenuScreen * tmp = menu;
    CAbstractMenuScreen * tmp2 = tmp;
    
    if(menu == NULL)    // vse uz je smazano (treba proto ze jsem BACKoval zpatky v menu)
        return;
    
    while(tmp->nextMenu != NULL){   // mazu od zacatku do konce
        
        tmp = tmp->nextMenu;
        delete tmp2;
        tmp2 = tmp;
    }
    
    delete tmp;
    
    menu = NULL;
}


CController::~CController(){
    
    deleteMenus();
}

void CController::showMenus(){    
        
    CAbstractMenuScreen * tmpmenu = menu;
    
    while(tmpmenu != NULL){
        tmpmenu->show();
        cout << "vybrano: "<< tmpmenu->readInput()<<endl;
        tmpmenu->setStuff(this);
        tmpmenu->setNextMenu();
        
        if( tmpmenu -> nextMenu == NULL && tmpmenu -> prevMenu == NULL ){
            deleteMenus();
            break;
        }
        else{
            tmpmenu = tmpmenu->nextMenu;
        }
    }
}

void CController::startGame(){
    if(!game.gameReady()){    //jsme na main menu a vybrali Exit
        //game.end();
        return;
    }
    else
        game.start();
    
    gameLoop(); 
    game.end();
}

void CController::gameLoop(){
                
    cin.ignore();
    game.currentPlayer = WHITE;
    game.currPlayerPtr = (game.player1->getPlayerColor() == WHITE ? game.player1 : game.player2);
        
    while(true){
        
        CCommand command;
        
        if(game.isCheckMate()){
            command.command = SURRENDER;
            command.executeCommand(game);
            return;
        }
        
        while(command.command == UNKNOWN){   
            command = game.currPlayerPtr-> getCommand(game);
        }
        
        command.executeCommand(game);
        
        
        if(game.exitRequest)
            break;
        
        if(game.movePerformed){
            game.switchPlayers();
            game.movePerformed = false;
        }
        
    }
    
}

void CController::endGame(){
    game.end();
}

void CController::printBoard() const{
    
    game.gameBoard.printBoard();
}

CGameSession& CController::getGameSess() {
    return game;
}

void CController::setTurn(COLOR col) {
    game.setTurn(col);
}
