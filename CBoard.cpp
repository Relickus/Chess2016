#include "CBishop.h"
#include "CKing.h"
#include "CKnight.h"
#include "CPawn.h"
#include "CTower.h"
#include "CQueen.h"
#include "AllExceptions.h"
#include "CGameSession.h"
#include "CPlayer.h"

#include <iostream>
#include <fstream>

#define WIDTH 8   // get rid of this ?
#define HEIGHT 8

using namespace std;

CBoard::CBoard() : width(WIDTH), height(HEIGHT), 
                LAST_ROW_DOWN(0),LAST_ROW_UP(7),INIT_ROW_DOWN(1),INIT_ROW_UP(6){
        
    for(int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; j++) {
            slotsArr[i][j].setValue( 8 - abs(i-3) - abs(j-3)); 
        }

    }
}

CBoard::CBoard(const CBoard& oth) : width(WIDTH), height(HEIGHT)  {

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            
            CPiece * pcs = oth.slotsArr[i][j].getHeldPiece();

            if(pcs == NULL)
                slotsArr[i][j].setHeldPiece(NULL);
            else{
                slotsArr[i][j].setHeldPiece( pcs->copyPiece(pcs) );
            }
        }
    }

    LAST_ROW_DOWN = oth.LAST_ROW_DOWN;
    LAST_ROW_UP = oth.LAST_ROW_UP;
    INIT_ROW_DOWN = oth.INIT_ROW_DOWN;
    INIT_ROW_UP = oth.INIT_ROW_UP;
    
}


void CBoard::moveFigure(const MyMove & move){
    
    if(getPiece(move.fromX,move.fromY)->getName() == PAWN){        
        if(move.toX == LAST_ROW_UP || move.toX == LAST_ROW_DOWN ){
            promotePawn(move);
            return;
        }
    }            
            
    CPiece * tmp = slotsArr[move.toX][move.toY].getHeldPiece();
    
    delete tmp;
    
    tmp = slotsArr[move.fromX][move.fromY].getHeldPiece();
        
    slotsArr[move.toX][move.toY].setHeldPiece(tmp);
    
    slotsArr[move.fromX][move.fromY].setHeldPiece(NULL);
    
    tmp->setRow(move.toX);
    tmp->setCol(move.toY);    
}


void CBoard::swapFigures(int r1, int c1, int r2, int c2){
    
        
    int tmpr = r1;
    int tmpc = c1;
    int tmpval1 = 0;
    int tmpval2 = 0;
    
    if(slotsArr[r1][c1].getHeldPiece() != NULL){
        tmpval1 = slotsArr[r1][c1].getHeldPiece()->getValue();
        //slotsArr[r1][c1].getHeldPiece().copyData(slotsArr[r2][c2].getHeldPiece())
    }
    
    if(slotsArr[r2][c2].getHeldPiece() != NULL){
        int tmpval2 = slotsArr[r2][c2].getHeldPiece()->getValue();
        slotsArr[r2][c2].getHeldPiece()->setRow(tmpr);
        slotsArr[r2][c2].getHeldPiece()->setCol(tmpc);
    }
    
    CPiece * tmp = slotsArr[r1][c1].getHeldPiece();
    slotsArr[r1][c1].setHeldPiece( slotsArr[r2][c2].getHeldPiece() );
    slotsArr[r2][c2].setHeldPiece(tmp);    
    
    slotsArr[r1][c1].getHeldPiece()->setValue(tmpval2);
    slotsArr[r2][c2].getHeldPiece()->setValue(tmpval1);
}

void CBoard::rotateBoard(){
    
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j<8; ++j){                
            swapFigures(i,j,7-i,7-j);            
        }             
    }    
    
    int tmp = LAST_ROW_DOWN;
    int tmp2 = INIT_ROW_DOWN;
    LAST_ROW_DOWN = LAST_ROW_UP;
    LAST_ROW_UP = tmp;
    INIT_ROW_DOWN = INIT_ROW_UP;
    INIT_ROW_UP = tmp2;
}

void CBoard::createPieces(COLOR colorDown){
    
    // [0][0] je dolni levy roh sachovnice    
    
    // standart possitions for Q and K when WHITE is down
    int queenPos = 3;
    int kingPos = 4;    
    
    COLOR colorUp = (colorDown == WHITE ? BLACK : WHITE);
    
    if(colorDown == BLACK){
        queenPos = 4;
        kingPos = 3;
    }
    
    // create opponent's peaces (up):
            
    try{
    
    slotsArr[7][0].setHeldPiece( new CTower(colorUp, 7,0) );
    slotsArr[7][7].setHeldPiece( new CTower(colorUp, 7,7) );
 
    slotsArr[7][1].setHeldPiece( new CKnight(colorUp, 7,1) );
    slotsArr[7][6].setHeldPiece( new CKnight(colorUp, 7,6) );
 
    slotsArr[7][2].setHeldPiece( new CBishop(colorUp, 7,2) );
    slotsArr[7][5].setHeldPiece( new CBishop(colorUp, 7,5) );
    
    slotsArr[7][queenPos].setHeldPiece( new CQueen(colorUp, 7,queenPos) );
    slotsArr[7][kingPos].setHeldPiece( new CKing(colorUp, 7,kingPos) );
    
    for(int i = 0; i < 8; ++i)
        slotsArr[6][i].setHeldPiece( new CPawn(colorUp,6,i) );
    
    // create Player1's peaces (down):
    
    slotsArr[0][0].setHeldPiece( new CTower(colorDown, 0, 0) );
    slotsArr[0][7].setHeldPiece( new CTower(colorDown, 0, 7) );
    
    slotsArr[0][1].setHeldPiece( new CKnight(colorDown, 0, 1) );
    slotsArr[0][6].setHeldPiece( new CKnight(colorDown, 0, 6) );
    
    slotsArr[0][2].setHeldPiece( new CBishop(colorDown, 0, 2) );
    slotsArr[0][5].setHeldPiece( new CBishop(colorDown, 0, 5) );
    
    slotsArr[0][queenPos].setHeldPiece( new CQueen(colorDown, 0, queenPos) );
    slotsArr[0][kingPos].setHeldPiece( new CKing(colorDown, 0, kingPos) );
    
    for(int i = 0; i < 8; ++i)
        slotsArr[1][i].setHeldPiece( new CPawn(colorDown, 1, i) ); 
   
    for(int i = 5; i >= 2; --i)
        for (int j = 0; j < 8; j++) {
            slotsArr[i][j].setHeldPiece(NULL);    
        }
    
    } catch (std::exception ex){
        throw "Chyba pri vytvareni figurek";
    }
    
    
}

void CBoard::translateMove(MyMove & move){
    
    move.fromX = 7-move.fromX;
    move.fromY = 7-move.fromY;
    move.toX = 7-move.toX;
    move.toY = 7-move.toY;
}

void CBoard::initBoard(const CGameSession * gameSess) {
    
    
    // CYKLI TO PRI SACHU - UDELAT INIT TAK ABYCH SE RYCHLE DOSTAL DO SACHU - osetrit cykleni
    // fixnout aby kral mohl vzit figurku kdyz je v sachu ale nesmi pri tom zase do sachu
    
   createPieces(gameSess->player1->getPlayerColor());    
}

void CBoard::printPossibleMoves(const MoveList & list) const{
    
    
    ///get possible moves - ziskej pole coordinates kam se figurka muze pohnout
    // pak vytiskni sachovnici viz dole, ale prazdny mista kam smi oznac * a mista kde by nekoho vzal oznac x
    
    
    CPiece * tmp=NULL;
    
    
    
    // cout << "_________________"<<endl;         
    
    for(int i=7; i>=0; --i){
        for (int j = 0; j<8; ++j) {
            if(j == 0)
                cout << i << " |";
            
            tmp  = slotsArr[i][j].getHeldPiece();
            
            if( tmp == NULL ){
                if(list.contains(MyMove(i,j)))
                    cout<<"*";
                else
                    cout << " ";
            }
            else{
                if(!list.contains(MyMove(i,j)))
                    tmp->printPiece(cout);
                else
                    cout<<"#";
            }
            cout <<"|";
            
            if(j == 7)
                cout<<endl;
        }
    }
    
   
    cout << "   a b c d e f g h"<<endl;   
    
    cout << endl<< endl;
    
    
}


void CBoard::printBoard() const{
    
    CPiece * tmp=NULL;
    
    // cout << "_________________"<<endl;         
    
    for(int i=7; i>=0; --i){
        for (int j = 0; j < 8; ++j) {
            if(j == 0)
                cout << i << " |";
            
            tmp  = slotsArr[i][j].getHeldPiece();
            
            if( tmp == NULL )
                cout << " ";
            else
                tmp->printPiece(cout);
            cout <<"|";
            
            if(j == 7)
                cout<<endl;
        }
    }
    
   
    cout << "   a b c d e f g h"<<endl;   
    
    cout << endl<< endl;
}

void CBoard::printDebug() const {

     CPiece * tmp=NULL;
    
    // cout << "_________________"<<endl;         
    
    for(int i=7; i>=0; --i){
        for (int j = 0; j < 8; ++j) {
            
            tmp  = slotsArr[i][j].getHeldPiece();
            
            if( tmp == NULL ){
                cout << "null na :"<<i<<","<<j<<endl;
                continue;
            }
            else{
                cout<<"pole: "<<i<<","<<j<<" -adresa: "<< tmp <<", fig: "<<tmp->getName()<<",  barva: "<<tmp->getColor()<<endl;
                
            }
            
        }
    }
     
    cout << endl<< endl;
    
}


void CBoard::printRotate() const {

    
      CPiece * tmp=NULL;
    
    // cout << "_________________"<<endl;         
    
    for(int i=0; i<8; ++i){
        for (int j = 7; j >= 0; --j) {
            if(j == 7)
                cout << i << " |";
            
            tmp  = slotsArr[i][j].getHeldPiece();
            
            if( tmp == NULL )
                cout << " ";
            else
                tmp->printPiece(cout);
            cout <<"|";
            
            if(j == 0)
                cout<<endl;
        }
    }
    
   
    cout << "   h g f e d c b a"<<endl;   
    
    cout << endl<< endl;
    
}

CPiece * CBoard::getPiece(int row, int col) const{
    
    return slotsArr[row][col].getHeldPiece();
}

bool CBoard::outOfBoard(int x, int y) const {
    return x < 0 || x >= 8 || y < 0 || y >= 8;
}

void CBoard::setField(int row, int col, CPiece * pc){
    slotsArr[row][col].setHeldPiece(pc);
}

void CBoard::copy(const CBoard & oth){
    
    if(this == &oth)
        return;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            
            delete slotsArr[i][j].getHeldPiece();
            
            CPiece * othpcs = oth.slotsArr[i][j].getHeldPiece();
            CPiece * pcs = NULL;
            if(othpcs != NULL){
                pcs= othpcs->copyPiece(othpcs);
            }
            
            slotsArr[i][j].setHeldPiece(pcs);
        }
    }
}

void CBoard::promotePawn(const MyMove& move) {

    COLOR col = slotsArr[move.fromX][move.fromY].getHeldPiece()->getColor();
    
    delete slotsArr[move.toX][move.toY].getHeldPiece();        
    delete slotsArr[move.fromX][move.fromY].getHeldPiece();
    slotsArr[move.fromX][move.fromY].setHeldPiece(NULL);
        
    slotsArr[move.toX][move.toY].setHeldPiece(new CQueen(col,move.toX,move.toY));    
}

int CBoard::getSlotValue(int x, int y) const {
    if(!outOfBoard(x,y)){
        return slotsArr[x][y].getValue();
    }
    return 0;
}

bool CBoard::tryMove(const MyMove & move,const CGameSession & gS) const {

    CBoard ficture(gS.getBoard());
    
    ficture.moveFigure(move);    
    
    //cout << "FICTURE BOARD: " << endl;
    //ficture.printBoard();
    
    CKing * tmpking = ficture.findKing(gS.currPlayerPtr->getPlayerColor());
    
    bool currentPlayerDown = (gS.currPlayerPtr == gS.player1);
        
    if(tmpking->isChecked(ficture,currentPlayerDown))
        return false;
    
    return true;
}

CKing * CBoard::findKing(COLOR col) const{    
    
    for(int i=0; i < 8 ;++i){
        for (int j = 0; j < 8; j++) {
            if(getPiece(i,j) == NULL)
                continue;
                    
            if(getPiece(i,j)->getName() == KING && getPiece(i,j)->getColor() == col){
                CPiece * tmp = getPiece(i,j);
                CKing * tmpking = dynamic_cast<CKing*>(tmp);
                return tmpking;
            }
        }
    }
    
    
}