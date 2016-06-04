#include "CGameSession.h"
#include "CPiece.h"
#include "CPawn.h"
#include "CFilePersistence.h"
#include <climits>
#include <fstream>

CGameSession::CGameSession() : ipHost(""), player1(NULL),player2(NULL), fileName(""), ready_flag(false),exitRequest(false) {

    persistence = new CFilePersistence(this);
    currentPlayer = whosTurn = WHITE;
    movePerformed = false;
}

CGameSession::~CGameSession() {
    end();
}

bool CGameSession::validateMove(const string & move){
    
    if(!validatePos(move.substr(0,2)) || !validatePos(move.substr(3))            
    || move.at(2) != ' ')
        return false;    
    
    return true;
}

bool CGameSession::validatePos(const string & pos){
    
    if(pos.at(0) < '0' || pos.at(0) > '7' || pos.at(1) < 'a' || pos.at(1) > 'h')
        return false;    
    
    return true;
}


MyMove CGameSession::waitForMove(){
    
    // pozdeji to vsechno tahnout pres CGUI (in i out)
        
    // tady bude jen opponent -> getMove() nebo makeMove() a kdyz to bude AI tak ta si v pameti zrotuje board
    // kdyz to bude human player tak se zavola opponent metoda zase z CHumanPlayer a tam se to nerotuje
    
}

void CGameSession::switchPlayers(){
        
    whosTurn = currentPlayer = (currentPlayer == WHITE ? BLACK : WHITE);
    currPlayerPtr = (currPlayerPtr == player1 ? player2 : player1);
    
    //gameBoard.rotateBoard();
}

void CGameSession::start() {

    if (fileName.empty())
        gameBoard.initBoard(this);
    
    gameBoard.printBoard();
    
    exitRequest = false;
}

void CGameSession::end() {
    delete player1;
    delete player2;
    delete persistence;
    
    player1 = NULL;
    player2 = NULL;
    persistence = NULL;
}

CBoard & CGameSession::getBoard() {
    return gameBoard;
}

void CGameSession::setGameReady() {
    ready_flag = true;
}

bool CGameSession::gameReady() const {
    return ready_flag;
}

void CGameSession::setPlayerColors(COLOR col) {

    player1->setPlayerColor(col);       

    if(col == WHITE){
        player2->setPlayerColor(BLACK);
        currPlayerPtr = player1;
    }
    else{
        player2->setPlayerColor(WHITE); 
        currPlayerPtr = player2;
    }
}

void CGameSession::setTurn(COLOR col) {
    currentPlayer = whosTurn = col;
}

bool CGameSession::performMove(MyMove& move){
            
    CPiece * tmp = gameBoard.getPiece(move.fromX,move.fromY);
    
    
    gameBoard.moveFigure(move);
    
    return true;
}