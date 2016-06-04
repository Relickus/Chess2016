
#include "CLocalPlayer.h"
#include "CGameSession.h"
#include "CPawn.h"
#include "CCommand.h"
#include <climits>


MyMove CLocalPlayer::getMove(CGameSession & gS){
//    
//    MyMove m = readInput(gS);
//    MyMove fict(-1,-1,-1,-1);
//    
//    if(m.isFicture())
//        return fict;
//    
//    CPiece * tmp = gS.gameBoard.getPiece(m.fromX,m.fromY);
//    
//    if(tmp == NULL){
//        cout << "Null field" << endl;
//        return fict;
//    }
//    else if(!(tmp->isFriendPiece(playerColor))){
//        cout << "Not your figure" << endl;
//        return fict;
//    }
//  
//    MoveList l;
//    
//    if(tmp->getName() == PAWN){
//        CPawn * pwn = dynamic_cast<CPawn*>(tmp);
//        
//        if(gS.currPlayerPtr == gS.player2){
//            
//            l = pwn->getLegalMovesDown(gS.gameBoard);
//        }
//        else
//            l = pwn->getLegalMovesUp(gS.gameBoard);
//    }
//    else
//        l = tmp->getLegalMoves(gS.gameBoard);
//        
//    if(!l.contains(m)){
//        cout << "Tento tah neni mozny." << endl;
//        return fict;
//    }
//    
//    return m;
}

void CLocalPlayer::badInput() const{
    
    cout << "Bad input, read manual before playing." << endl;        
}

string CLocalPlayer::readInput() const{
                   
    string tmpstr;
    MyMove fict(-1,-1,-1,-1);
    CCommand com;
    
    getline(cin,tmpstr);
        
    if(!cin.good() || tmpstr.empty()){
        throw BadInputException();
    }  
    
    return tmpstr;
}
CLocalPlayer::CLocalPlayer() {

}

CLocalPlayer::~CLocalPlayer() {

}

CCommand CLocalPlayer::getCommand(CGameSession & gS) {

    CCommand com;
    string tmp;
    
    try{
    
    cout<<"Na tahu je "<< (gS.currentPlayer == WHITE ? "BILY" : "CERNY") <<endl;
    cout<<"Zadejte prikaz:"<<endl;        
    tmp = readInput(); 
    
    }catch(BadInputException & ex){
        cout << "Bad input exc." << endl;
        return CCommand(UNKNOWN);
    }
     
    try{
    com.makeCommand(tmp);   // naplni com zadanym commandem od uzivatele
    }catch(BadCommandException & ex){
        cout << "Neplatny command" << endl;
        return CCommand(UNKNOWN);
    }
    return com;
}
