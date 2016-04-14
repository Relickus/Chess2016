#include "CBoard.h"
#include "CSlot.h"
#include "AllDefines.h"
#include "AllPieces.h"

#define WIDTH 8   // get rid of this ?
#define HEIGHT 8

using namespace std;

CBoard::CBoard() : width(WIDTH), height(HEIGHT) {
    
    
    
}

CBoard::~CBoard(){
    
    for(int i = 0 ; i < width ; ++i){
       for(int j = 0 ; j < height ; ++j){

           delete slotsArr[i][j].getHeldPiece();
       }
    }
    
}


bool CBoard::createPieces(){
    
    // [0][0] je dolni levy roh sachovnice
    
    // create Blacks:
    
    slotsArr[7][0].setHeldPiece( new CTower(BLACK) );
    slotsArr[7][7].setHeldPiece( new CTower(BLACK) );
    
    slotsArr[7][1].setHeldPiece( new CKnight(BLACK) );
    slotsArr[7][6].setHeldPiece( new CKnight(BLACK) );
    
    slotsArr[7][2].setHeldPiece( new CBishop(BLACK) );
    slotsArr[7][5].setHeldPiece( new CBishop(BLACK) );
    
    slotsArr[7][3].setHeldPiece( new CQueen(BLACK) );
    slotsArr[7][4].setHeldPiece( new CKing(BLACK) );
    
    for(int i = 0; i < 8; ++i)
        slotsArr[6][i].setHeldPiece( new CPawn(BLACK) );
    
    // create Whites:
    
    slotsArr[0][0].setHeldPiece( new CTower(WHITE) );
    slotsArr[0][7].setHeldPiece( new CTower(WHITE) );
    
    slotsArr[0][1].setHeldPiece( new CKnight(WHITE) );
    slotsArr[0][6].setHeldPiece( new CKnight(WHITE) );
    
    slotsArr[0][2].setHeldPiece( new CBishop(WHITE) );
    slotsArr[0][5].setHeldPiece( new CBishop(WHITE) );
    
    slotsArr[0][3].setHeldPiece( new CQueen(WHITE) );
    slotsArr[0][4].setHeldPiece( new CKing(WHITE) );
    
    for(int i = 0; i < 8; ++i)
        slotsArr[1][i].setHeldPiece( new CPawn(WHITE) );
    
}

void CBoard::printBoard() const{
    
    for(int r = 0; r < 9; ++r ){
        cout << "-";     
    }
    
    for(int i=0; i<width; ++i){
        for (int j = 0; j < height; j++) {
            if(j == 0)
                cout << "|";
            
            slotsArr[i][j].getHeldPiece()->printPiece();
            cout <<"|";
            
            if(j == height-1)
                cout<<endl;
        }
    }
    
    for(int r = 0; r < 9; ++r ){
        cout << "-";     
    }
    cout << endl<< endl;
}
