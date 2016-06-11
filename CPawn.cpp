#include "CPawn.h"
#include "CQueen.h"
#include "CGameSession.h"

CPawn::CPawn() {

    name = PAWN;
    

    moveList.reserve(15);
    value = 1;
}

CPawn::~CPawn() {

}

CPawn::CPawn(COLOR clr , int row, int col) : CPiece(clr,row,col) {
    name = PAWN;
    

    moveList.reserve(15);
    value = 1;

}

CMoveList & CPawn::getLegalMovesDown(const CBoard & board) {
    
    moveList.clear();
    

    int newRow = getRow()-1;
    int newCol = getCol();

    int firststep = this->checkField(newRow, newCol, board, false);
    
    this->checkField(getRow() - 1, getCol() - 1, board, true);
    this->checkField(getRow() - 1, getCol() + 1, board, true);

    if (getRow() == board.INIT_ROW_UP && firststep != 2) { //initial row, pawn not moved yet  
        newRow = getRow()-2;
        this->checkField(newRow, newCol, board, false);
    }

    return moveList;
}

CMoveList & CPawn::getLegalMovesUp(const CBoard & board) {
    
    moveList.clear();
    

    int newRow = getRow()+1;
    int newCol = getCol();

    int firststep = this->checkField(newRow, newCol, board, false);
    
    this->checkField(getRow() + 1, getCol() - 1, board, true);
    this->checkField(getRow() + 1, getCol() + 1, board, true);

    if (getRow() == board.INIT_ROW_DOWN && firststep != 2) { //initial row, pawn not moved yet  
        newRow = getRow()+2;
        this->checkField(newRow, newCol, board, false);
    }

    return moveList;
}

CMoveList & CPawn::getLegalMoves(const CGameSession & gS) {
    if(gS.currPlayerPtr == gS.player1)
        return getLegalMovesUp(gS.getBoard());
    else
        return getLegalMovesDown(gS.getBoard());
    
}

int CPawn::checkField(int x, int y, const CBoard& board, bool sidestep) {

    if (board.outOfBoard(x, y))
        return 1;

    if (x == getRow() && y == getCol())
        return 0;

    CPiece * tmp = board.getPiece(x, y);

    if (!sidestep) {
        if (tmp != NULL) {  // nekdo stoji primo pred pawnem
            return 2;
        } else {
            moveList.add(x, y,rowPos,colPos,NULL);
            return 0;
        }
    }

    // is sidestep

    if (tmp == NULL)
        return 1;

    else if (isFriendPiece(tmp)) {
        return 1;
    } else {
        moveList.add(x, y,rowPos,colPos,tmp);
        return 0;
    }

}

CPiece* CPawn::copyPiece(const CPiece * pcs) const{
    return new CPawn(pcs->getColor(),pcs->getRow(),pcs->getCol());
}