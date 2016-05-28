#include "CGameSession.h"

CGameSession::CGameSession() : player1color(WHITE), ipHost(""), opponent(NULL), difficulty(0), fileName(""){

    //gameBoard = CBoard::initBoard();
}

CGameSession::~CGameSession(){
    
    
}

void CGameSession::start(){
    
    if(!fileName.empty()){
     //  gameBoard.loadFromFile(fileName);
    }
    
    gameBoard.initBoard(this);
    gameBoard.printBoard();
}

void CGameSession::end(){
    
}

const CBoard & CGameSession::getBoard() const{    
    return gameBoard;
}