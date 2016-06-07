#include <string>
#include "CCommand.h"
#include "CPawn.h"

#include "MyMove.h"
#include "CPersistence.h"
#include "CGameSession.h"
#include "AllExceptions.h"


CCommand::CCommand() {
    command = UNKNOWN;
}
CCommand::CCommand(COMMAND com) {
    command = com;
}

CCommand::CCommand(const MyMove& mv) {
    move = mv;
    command = MAKEMOVE;
}


void CCommand::executeCommand(CGameSession & gS) {
    
    switch(command){
        
        case(EXIT):
            exitQuery(gS);
            break; 
        case(SAVE):
            saveQuery(gS);
            break;         
        case(MOVES):
            movesQuery(gS);
            break;
        case(ROTATE):
            rotateQuery(gS);
             break;
        case(MAKEMOVE):
            makeMoveQuery(gS);
            break;
        case(CHECK):
            checkQuery(gS);
            break;
        case(SURRENDER):
            surrenderQuery(gS);
            break;
        case(TIE):
            tieQuery(gS);
            break;
            
        default:
            break;
    }
}


void CCommand::makeCommand(const string & str) {

    if(str.size() == 8){        
        if(str.substr(0,6) == "moves "){
            if(CGameSession::validatePos(str.substr(6,2))){
                
                command = MOVES;
                x = str.substr(6,2).at(0) - 48;
                y = str.substr(6,2).at(1) - 48 - 49;
            }
            
        }
        
    }
    else if(str == "rotate"){
        command = ROTATE;
        
    }
    else if(str == "exit")
            command = EXIT;
    else if(str == "save")
            command = SAVE;
    else if(str.size() == 5){
        if(CGameSession::validateMove(str))
            command = MAKEMOVE;
            MyMove m(str);
            move = m;
    }
    
    else{
        command = UNKNOWN;
        throw BadCommandException();
    }
}

void CCommand::exitQuery(CGameSession & gS) const{
    gS.exitRequest = true;
}
void CCommand::saveQuery(CGameSession & gS) const{
     
    gS.persistence->save();
}

void CCommand::movesQuery(CGameSession & gS) const{          

    CPiece * tmp = gS.gameBoard.getPiece(x,y);

    if(tmp == NULL){
        cout << "Empty field."<<endl;
        //cin.ignore(INT_MAX,'\n');
        return;
    }
    if(!(tmp->isFriendPiece(gS.currentPlayer))){
        cout << "Not your figure."<<endl;
        //cin.ignore(INT_MAX,'\n');
        return;
    }

    MoveList l = tmp->getLegalMoves(gS);

    gS.gameBoard.printPossibleMoves(l);
        
}

void CCommand::makeMoveQuery(CGameSession & gS) const{          

    MoveList l;
    CPiece * tmp = gS.gameBoard.getPiece(move.fromX,move.fromY);
    
    if(tmp == NULL){
        cout << "Empty field."<<endl;
        //cin.ignore(INT_MAX,'\n');
        return;
    }
    if(!(tmp->isFriendPiece(gS.currentPlayer))){
        cout << "Not your figure."<<endl;
        //cin.ignore(INT_MAX,'\n');
        return;
    }
    
    // legalni figurka 
    
     l = tmp->getLegalMoves(gS);

    if(!l.contains(move)){
        cout << "Tento tah neni mozny." << endl;
        return;
    }
      
    if( ! gS.gameBoard.tryMove(move,gS)){
    
        cout << "Tento tah vede na šach, vyberte jiný tah." << endl;    
        return;
    }
    else{
        gS.performMove(move);
        gS.gameBoard.printBoard();
        gS.movePerformed = true;
    }
    
}

void CCommand::rotateQuery(CGameSession & gS) const {
    gS.gameBoard.printRotate();
}


void CCommand::surrenderQuery(CGameSession & gS) const{
    cout << "======= Checkmate! Vyhrava "<<(gS.currentPlayer==BLACK?"BILY ":"CERNY ")<<"======="<<endl;
    exitQuery(gS);
}


void CCommand::checkQuery(CGameSession & gS) const{
    cout << "Pozor, jste v sachu!" << endl;    
}

void CCommand::tieQuery(CGameSession& gS) const {
    cout<<" Nastala patova situace, nikdo nevyhral."<<endl;
    exitQuery(gS);
}
