#include "CBishop.h"
#include "CKing.h"
#include "CKnight.h"
#include "CPawn.h"
#include "CTower.h"
#include "CQueen.h"

#include "CGameSession.h"
#include "CBoard.h"
#include "MyMove.h"

#include <iostream>

#define WIDTH 8   // get rid of this ?
#define HEIGHT 8

using namespace std;

CBoard::CBoard() : width(WIDTH), height(HEIGHT) {
        
}

CBoard::~CBoard(){
    
    // není potřeba - sachovnice je staticky alokovane 2D pole CSlotu a pri jeho destrukci se volaji destruktory jednotlivych policek
    // tedy volaj se destruktor CSlot na kazdy policko
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
    
    slotsArr[7][0].setHeldPiece( new CTower(colorUp) );
    slotsArr[7][7].setHeldPiece( new CTower(colorUp) );
    
    slotsArr[7][1].setHeldPiece( new CKnight(colorUp) );
    slotsArr[7][6].setHeldPiece( new CKnight(colorUp) );
    
    slotsArr[7][2].setHeldPiece( new CBishop(colorUp) );
    slotsArr[7][5].setHeldPiece( new CBishop(colorUp) );
    
    slotsArr[7][queenPos].setHeldPiece( new CQueen(colorUp) );
    slotsArr[7][kingPos].setHeldPiece( new CKing(colorUp) );
    
    for(int i = 0; i < 8; ++i)
        slotsArr[6][i].setHeldPiece( new CPawn(colorUp) );
    
    // create Player1's peaces (down):
    
    slotsArr[0][0].setHeldPiece( new CTower(colorDown) );
    slotsArr[0][7].setHeldPiece( new CTower(colorDown) );
    
    slotsArr[0][1].setHeldPiece( new CKnight(colorDown) );
    slotsArr[0][6].setHeldPiece( new CKnight(colorDown) );
    
    slotsArr[0][2].setHeldPiece( new CBishop(colorDown) );
    slotsArr[0][5].setHeldPiece( new CBishop(colorDown) );
    
    slotsArr[0][queenPos].setHeldPiece( new CQueen(colorDown) );
    slotsArr[0][kingPos].setHeldPiece( new CKing(colorDown) );
    
    for(int i = 0; i < 8; ++i)
        slotsArr[1][i].setHeldPiece( new CPawn(colorDown) );
    
    } catch (std::exception ex){
        throw "Chyba pri vytvareni figurek";
    }
    
    
}

void CBoard::initBoard(const CGameSession * gameSess) {
    
   createPieces(gameSess->player1color);    
}

void CBoard::printPossibleMoves(CPiece * pc) const{
    
    
    ///get possible moves - ziskej pole coordinates kam se figurka muze pohnout
    // pak vytiskni sachovnici viz dole, ale prazdny mista kam smi oznac * a mista kde by nekoho vzal oznac x
    
    
    CPiece * tmp=NULL;
    
    
    
    // cout << "_________________"<<endl;         
    
    for(int i=0; i<width; ++i){
        for (int j = 0; j < height; j++) {
            if(j == 0)
                cout << 7-i << " |";
            
            tmp  = slotsArr[i][j].getHeldPiece();
            
            if( tmp == NULL )
                cout << " ";
            else
                tmp->printPiece();
            cout <<"|";
            
            if(j == height-1)
                cout<<endl;
        }
    }
    
   
    cout << "   a b c d e f g h"<<endl;   
    
    cout << endl<< endl;
    
    
}


void CBoard::printBoard() const{
    
    CPiece * tmp=NULL;
    
    // cout << "_________________"<<endl;         
    
    for(int i=0; i<width; ++i){
        for (int j = 0; j < height; j++) {
            if(j == 0)
                cout << 7-i << " |";
            
            tmp  = slotsArr[i][j].getHeldPiece();
            
            if( tmp == NULL )
                cout << " ";
            else
                tmp->printPiece();
            cout <<"|";
            
            if(j == height-1)
                cout<<endl;
        }
    }
    
   
    cout << "   a b c d e f g h"<<endl;   
    
    cout << endl<< endl;
}

//void CBoard::loadFromFile(const string & filename){
//    
//    ifstream ifs("filename");
//    string rowstr;
//    
//    
//    for(int i = 0; i < 8; ++i){     
//        getline(ifs,rowstr,'\n');
//        if(!ifs.good())
//            throw "CHYBA VE CTENI SOUBORU";
//        
//        for(int j = 0; j < 8; ++j){
//            slotsArr[i][j] = CPiece::getPieceByLetter(rowstr.at(j));
//        }
//        
//        
//    }
//    
//}

CPiece * CBoard::getPiece(int x, int y) const{
    
    return slotsArr[x][y].getHeldPiece();
}

bool CBoard::outOfBoard(int x, int y) const {
    return x < 0 || x > 8 || y < 0 || y > 8;
}

bool CBoard::fieldChecked(int x, int y, CPiece * playerspiece) const {  // mozna vratit nejaky pole figurek co to policko sachujou?
    
    //search left up diagonal for checking enemy piecies 
    int newX = x-1;
    int newY = y+1;
    
    while(!outOfBoard(newX,newY)){
        
        if(getPiece(newX,newY) == NULL)
            continue;
        
        
        if(getPiece(newX,newY)->isFriendPiece(playerspiece))
                break;
        
         else{   // enemy figure
                
            MyMove tmp(x,y,getPiece(newX,newY));
            MoveList tmplist = getPiece(newX,newY)->getLegalMoves(*this);
             
            if(tmplist.contains(tmp))   // je tam nejaka enemy figurka ktera toto policko checkuje
                return true;
            else
                break;
        }
        
        newX = newX--;
        newY = newY++;
    }
    
    // right up
    
     newX = x+1;
     newY = x+1;
     
     while(!outOfBoard(newX,newY)){
        
        if(getPiece(newX,newY) == NULL)
            continue;
        
        
        if(getPiece(newX,newY)->isFriendPiece(playerspiece))
                break;
        
         else{   // enemy figure
                
            MyMove tmp(x,y,getPiece(newX,newY));
            MoveList tmplist = getPiece(newX,newY)->getLegalMoves(*this);
             
            if(tmplist.contains(tmp))   // je tam nejaka enemy figurka ktera toto policko checkuje
                return true;
            else
                break;
        }
        
        newX = newX++;
        newY = newY++;
    }
     
     // left down
    
     newX = x-1;
     newY = x-1;
     
     while(!outOfBoard(newX,newY)){
        
        if(getPiece(newX,newY) == NULL)
            continue;
        
        
        if(getPiece(newX,newY)->isFriendPiece(playerspiece))
                break;
        
         else{   // enemy figure
                
            MyMove tmp(x,y,getPiece(newX,newY));
            MoveList tmplist = getPiece(newX,newY)->getLegalMoves(*this);
             
            if(tmplist.contains(tmp))   // je tam nejaka enemy figurka ktera toto policko checkuje
                return true;
            else
                break;
        }
        
        newX = newX--;
        newY = newY--;
    }
     
     // right down
    
     newX = x+1;
     newY = x-1;
     
     while(!outOfBoard(newX,newY)){
        
        if(getPiece(newX,newY) == NULL)
            continue;
        
        
        if(getPiece(newX,newY)->isFriendPiece(playerspiece))
                break;
        
         else{   // enemy figure
                
            MyMove tmp(x,y,getPiece(newX,newY));
            MoveList tmplist = getPiece(newX,newY)->getLegalMoves(*this);
             
            if(tmplist.contains(tmp))   // je tam nejaka enemy figurka ktera toto policko checkuje
                return true;
            else
                break;
        }
        
        newX = newX++;
        newY = newY--;
    }
     
    
    return false;
}
