#include "CPawn.h"
#include "CQueen.h"

CPawn::CPawn() {

    name = PAWN;
    isLongRunner = false;

    moveList.reserve(15);
    value = 1;
}

CPawn::~CPawn() {

}

CPawn::CPawn(COLOR clr , int row, int col) : CPiece(clr,row,col) {
    name = PAWN;
    isLongRunner = false;

    moveList.reserve(15);
    value = 1;

}
//
//void CPawn::printPiece() const{
//        
//}


MoveList & CPawn::getLegalMovesDown(const CBoard & board) {
    
    moveList.clear();
    

    int newRow = getRow()-1;
    int newCol = getCol();

    this->checkField(newRow, newCol, board, false);
    
    this->checkField(getRow() - 1, getCol() - 1, board, true);
    this->checkField(getRow() - 1, getCol() + 1, board, true);

    if (getRow() == board.INIT_ROW_UP) { //initial row, pawn not moved yet  
        newRow = getRow()-2;
        this->checkField(newRow, newCol, board, false);
    }

    return moveList;
}

MoveList & CPawn::getLegalMovesUp(const CBoard & board) {
    
    moveList.clear();
    

    int newRow = getRow()+1;
    int newCol = getCol();

    this->checkField(newRow, newCol, board, false);
    
    this->checkField(getRow() + 1, getCol() - 1, board, true);
    this->checkField(getRow() + 1, getCol() + 1, board, true);

    if (getRow() == board.INIT_ROW_DOWN) { //initial row, pawn not moved yet  
        newRow = getRow()+2;
        this->checkField(newRow, newCol, board, false);
    }

    return moveList;
}

MoveList & CPawn::getLegalMoves(const CBoard & board) {
    cout << "ZAVOLANA STARA METODA GETLEGAL MOVES VE PAWNOVI" << endl;
}

int CPawn::checkField(int x, int y, const CBoard& board, bool sidestep) {

    if (board.outOfBoard(x, y))
        return 1;

    if (x == getRow() && y == getCol())
        return 0;

    CPiece * tmp = board.getPiece(x, y);

    if (!sidestep) {
        if (tmp != NULL) {
            return 1;
        } else {
            moveList.add(x, y,rowPos,colPos);
            return 0;
        }
    }

    // is sidestep

    if (tmp == NULL)
        return 1;

    else if (isFriendPiece(tmp)) {
        return 1;
    } else {
        moveList.add(x, y,rowPos,colPos);
        return 0;
    }

}
