#include <string>
#include "CCommand.h"
#include "CPawn.h"


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

    MoveList l;

    if(tmp->getName() == PAWN){
     CPawn * pwn = dynamic_cast<CPawn*>(tmp);

        if(gS.currPlayerPtr == gS.player2){

            l = pwn->getLegalMovesDown(gS.gameBoard);
        }
        else
            l = pwn->getLegalMovesUp(gS.gameBoard);
    }
    else
        l = tmp->getLegalMoves(gS.gameBoard);

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
    
    if(tmp->getName() == PAWN){
     CPawn * pwn = dynamic_cast<CPawn*>(tmp);

        if(gS.currPlayerPtr == gS.player2){

            l = pwn->getLegalMovesDown(gS.gameBoard);
            if(move.toX == CBoard::LAST_ROW_DOWN){ // hodla jit na protejsi kraj -> promotion
                
                gS.gameBoard.promotePawn(move);                        
                gS.gameBoard.printBoard();    
                gS.movePerformed = true;
                return;
            }
        }
        else{
            l = pwn->getLegalMovesUp(gS.gameBoard);
            if(move.toX == CBoard::LAST_ROW_UP){   // hodla jit na protejsi kraj -> promotion
                
               gS.gameBoard.promotePawn(move);    
               gS.gameBoard.printBoard(); 
               gS.movePerformed = true;
               return;
            }
        }
    }
    else
        l = tmp->getLegalMoves(gS.gameBoard);

    if(!l.contains(move)){
        cout << "Tento tah neni mozny." << endl;
        return;
    }
      
    gS.gameBoard.moveFigure(move);
    gS.gameBoard.printBoard();
    
    gS.movePerformed = true;
}

void CCommand::rotateQuery(CGameSession & gS) const {
    gS.gameBoard.printRotate();
}
