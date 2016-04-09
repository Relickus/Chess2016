#include "CBoard.h"
#include "CSlot.h"

#define WIDTH 8
#define HEIGHT 8

CBoard::CBoard() : width(WIDTH), height(HEIGHT) {

    
    
    
}

CBoard::~CBoard(){
}

void CBoard::printBoard() const{
    
    for(int i=0; i<width; ++i){
        for (int j = 0; j < height; j++) {
            slotsArr[i][j].getHeldPiece()->printPiece();
        }
    }
        
}
