#include "CGameSession.h"
#include "CFilePersistence.h"
#include "CPlayer.h"
#include "CLocalPlayer.h"
#include "CRemotePlayer.h"
#include "CPiece.h"
#include "CMyMove.h"
#include "CMoveList.h"
#include <climits>
#include <fstream>

CGameSession::CGameSession() 
    
    :  fileName(""),ready_flag(false),exitRequest(false),onlineGame(false),movePerformed(false),
        whosTurn(WHITE),currentPlayer(WHITE), player1(NULL),player2(NULL), currPlayerPtr(NULL), persistence(NULL){

    persistence = new CFilePersistence(this);
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


void CGameSession::switchPlayers(){
        
    whosTurn = currentPlayer = (currentPlayer == WHITE ? BLACK : WHITE);
    currPlayerPtr = (currPlayerPtr == player1 ? player2 : player1);
    
    //gameBoard.rotateBoard();
}

void CGameSession::start() {

    if (fileName.empty())
        gameBoard.initBoard(player1->getPlayerColor());
       
    //else - game already loaded from the file
        
    assignKings(); 
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

const CBoard & CGameSession::getBoard() const {
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
    currentPlayer = WHITE;
}

void CGameSession::setTurn(COLOR col) {
    currentPlayer = whosTurn = col;
}

bool CGameSession::performMove(const CMyMove& move){
                
    gameBoard.moveFigure(move);
    
    return true;
}



bool CGameSession::isCheckMate() const {
    
    currPlayerPtr->findAllFigures(gameBoard);
    CMoveList l;
    
    for(size_t i = 0; i < currPlayerPtr->figuresVec.size(); ++i){
        CMoveList tmp = currPlayerPtr->figuresVec.at(i)->getLegalMoves(*this);
        l.concat(tmp);
    }
    
    if(l.isEmpty())
        return true;
    
    for(size_t i = 0; i < l.size(); ++i){
        
        if ( gameBoard.tryMove(l.getMove(i),*this) )
            return false;
    }
    
    return true;
}

void CGameSession::assignKings() {

    COLOR col = player1->getPlayerColor();    
    player1->setKing( gameBoard.findKing(col) );
    
    col = player2->getPlayerColor();    
    player2->setKing( gameBoard.findKing(col));
    
}

/*void CGameSession::updateKings(){
    assignKings();
}*/

bool CGameSession::isTie() const {
    player1->findAllFigures(gameBoard);
    player2->findAllFigures(gameBoard);
    
   // cout<<"pl1 ma figurek: "<<player1->figuresVec.size()<<", pl2 ma: "<<player2->figuresVec.size()<<endl;
    
    if( (player1->figuresVec.size() +  player2->figuresVec.size()) == 2)   //pokud zbyvaji jen 2 figurky musi to byt kralove
        return true;
    
    return false;
}

void CGameSession::netGameInit() {
    
    int sock = -1;
    
    while(sock == -1){        
        networking.inputServerInfo();
        sock = networking.getSocket();
        if(sock == -1)
            cout << "Klientský socket se nepodařilo otevřít." << endl;
    }
    
    onlineGame = true;
    player1 = new CLocalPlayer();

    player2 = new CRemotePlayer(sock);

    COLOR col = networking.recvPlayerColor(sock);
    cout << "Vaše barva je "<< (col==WHITE?"BÍLÁ":"ČERNÁ") << endl;

    setPlayerColors(col);
    networking.waitForStart(sock);

      //wait for GO
    setGameReady();
}
