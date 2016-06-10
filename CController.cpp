#include "CController.h"
#include "CMainMenu.h"
#include "CDifficultyMenu.h"
#include "CColorMenu.h"
#include "CCommand.h"
#include "CPlayer.h"

#include "CAbstractMenuScreen.h"
#include "CGameSession.h"

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
        game.end();
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
        
//        cout<<"===================="<<endl;
//        game.gameBoard.printDebug();
//        game.gameBoard.printBoard();
//        cout<<"===================="<<endl;
        
        CCommand command;
        
        if(game.isCheckMate()){
            command.command = SURRENDER;
            command.executeCommand(game);
             
            //if(game.currPlayerPtr == game.player1)  // hral jsem ja, poslu svuj tah druhymu
            //    game.player2-> sendMove(command.move);
            
            return;
        }
        else if(game.isTie()){
            command.command = TIE;
            command.executeCommand(game);
          //  if(game.currPlayerPtr == game.player1)  // hral jsem ja, poslu svuj tah druhymu
          //      game.player2-> sendMove(command.move);
            return;
        }
        else if(game.currPlayerPtr->kingIsChecked(game)){
            CCommand checkcom;
            checkcom.command = CHECK;
            checkcom.executeCommand(game);
        }
        
        while(command.command == UNKNOWN){   
            if(game.currPlayerPtr == game.player2)
                cout << "Cekam na tah protihrace..." << endl;
            command = game.currPlayerPtr-> getCommand(game);
        }
        
        command.executeCommand(game);        
                
        if(game.exitRequest)
            break;
        
        if(game.movePerformed){    
          if(game.onlineGame && game.currPlayerPtr == game.player1){  // hral jsem ja, poslu svuj tah druhymu
               game.networking.sendCommand(command,game.player2->getSocket());
            }
        
            game.switchPlayers();
            game.movePerformed = false;
            
        }
        
    }
    
}

void CController::endGame(){
    game.end();
}


CGameSession& CController::getGameSess() {
    return game;
}

