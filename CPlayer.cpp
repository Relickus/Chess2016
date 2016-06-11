#include "CPlayer.h"
#include "CKing.h"

#include "CGameSession.h"
#include "CMoveList.h"
#include "CPiece.h"

CPlayer::CPlayer() : playersKing(NULL){
    
}

CPlayer::~CPlayer() {

}

COLOR CPlayer::getPlayerColor() const {
    return playerColor;
}

void CPlayer::printPlayerColor(ostream & os) const {
    char c = toupper(getPlayerColor());
    os << c;
}

void CPlayer::setPlayerColor(COLOR col) {
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

bool CPlayer::kingIsChecked(const CGameSession & gS) const{
    
    bool tmp = (gS.currPlayerPtr == gS.player1);
    return playersKing->isChecked(gS.getBoard(),tmp);
}

void CPlayer::setKing(CKing* k) {
    playersKing = k;
}

int CPlayer::getSocket() const {
    return 0;
}
