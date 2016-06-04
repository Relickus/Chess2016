#include "CPlayer.h"

CPlayer::CPlayer(){
    
}

CPlayer::CPlayer(const CPlayer& orig) {

}

CPlayer::~CPlayer(){
    
}

COLOR CPlayer::getPlayerColor() const {
    return playerColor;
}

COLOR CPlayer::setPlayerColor(COLOR col) {
    playerColor = col;
}

void CPlayer::findAllFigures(const CBoard& board){
    
    figuresVec.clear();
    
    for(int i=0; i < 8; ++i){
        for (int j = 0; j < 8; j++) {
            
            if(board.getPiece(i,j) == NULL)
                continue;
            else if(board.getPiece(i,j)->isFriendPiece(playerColor)){
                figuresVec.push_back(board.getPiece(i,j));
            }
        }

        
    }
    
}