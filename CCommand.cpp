#include <string>
#include "CCommand.h"
#include "CPawn.h"

#include "MyMove.h"
#include "CPersistence.h"
#include "CGameSession.h"
#include "AllExceptions.h"
#include "CPlayer.h"


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
        if(CGameSession::validateMove(str)){
            command = MAKEMOVE;
            MyMove m(str);
            move = m;
        }
        else{
            command = UNKNOWN;
            throw BadCommandException();
        }
    }
    
    else{
        command = UNKNOWN;
        throw BadCommandException();
    }
}

void CCommand::exitQuery(CGameSession & gS) const{
    if(gS.onlineGame){  // exit pozadavek vzesel ode me
        if( gS.currPlayerPtr==gS.player1){
            CCommand com(EXIT);
            gS.networking.sendCommand(com,gS.player2->getSocket());
        }
        else{
            cout << "Prijat EXIT pozadavek."<<endl<<"Konec hry." << endl;
        }
    }
    gS.exitRequest = true;
}
void CCommand::saveQuery(CGameSession & gS) const{
     
    gS.persistence->save();
}

void CCommand::movesQuery(CGameSession & gS) const{          

    CPiece * tmp = gS.getBoard().getPiece(x,y);

    if(tmp == NULL){
        cout << "Prázdné pole."<<endl;
        //cin.ignore(INT_MAX,'\n');
        return;
    }
    if(!(tmp->isFriendPiece(gS.currentPlayer))){
        cout << "Toto není tvá figurka."<<endl;
        //cin.ignore(INT_MAX,'\n');
        return;
    }

    MoveList l = tmp->getLegalMoves(gS);

    gS.getBoard().printPossibleMoves(l);
        
}

void CCommand::makeMoveQuery(CGameSession & gS) const{          

    MoveList l;
    CPiece * tmp = gS.getBoard().getPiece(move.fromX,move.fromY);
    
    if(tmp == NULL){
        cout << "Prázdné pole."<<endl;
        //cin.ignore(INT_MAX,'\n');
        return;
    }
    if(!(tmp->isFriendPiece(gS.currentPlayer))){
        cout << "Toto není tvá figurka."<<endl;
        //cin.ignore(INT_MAX,'\n');
        return;
    }
    
    // legalni figurka 
    
     l = tmp->getLegalMoves(gS);

    if(!l.contains(move)){
        cout << "Tento tah není možný." << endl;
        return;
    }
      
    if( ! gS.getBoard().tryMove(move,gS)){
    
        cout << "Tento tah vede na šach, vyberte jiný tah." << endl;    
        return;
    }
    else{
        gS.performMove(move);
        gS.getBoard().printBoard();
        gS.movePerformed = true;
    }
    
}

void CCommand::rotateQuery(const CGameSession & gS) const {
    gS.getBoard().printRotate();
}


void CCommand::surrenderQuery(CGameSession & gS) const{
    cout << "======= Checkmate! Vyhrává "<<(gS.currentPlayer==BLACK?"BÍLÝ ":"ČERNÝ ")<<"======="<<endl;
    exitQuery(gS);
}


void CCommand::checkQuery(CGameSession & gS) const{
    cout << "Pozor, hráč "<< (gS.currentPlayer==BLACK?"ČERNÝ":"BÍLÝ")<<" je v šachu!" << endl;    
}

void CCommand::tieQuery(CGameSession& gS) const {
    cout<<" Nastala patová situace, nikdo nevyhrál."<<endl;
    exitQuery(gS);
}

const MyMove& CCommand::getMoveRef() const{

    return move;
}
