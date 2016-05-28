#include "CPawn.h"
#include "CQueen.h"

CPawn::CPawn() {

    name = PAWN;
    isLongRunner = false;

    moveList.reserve(15);

}

CPawn::~CPawn() {

}

CPawn::CPawn(COLOR col) : CPiece(col) {
    name = PAWN;
    isLongRunner = false;

    moveList.reserve(15);

}
//
//void CPawn::printPiece() const{
//        
//}

MoveList & CPawn::getLegalMoves(const CBoard & board) {

    moveList.clear();

    int newX = getX();
    int newY = getY() + 1;

    this->checkField(newX, newY, board, false);
    this->checkField(newX - 1, newY, board, true);
    this->checkField(newX + 1, newY, board, true);

    if (getY() == INIT_ROW) { //initial row, pawn not moved yet  
        newY++;
        this->checkField(newX, newY, board, false);
    }

    return moveList;
}

int CPawn::checkField(int x, int y, const CBoard& board, bool sidestep) {

    if (board.outOfBoard(x, y))
        return 1;

    if (x == getX() && y == getY())
        return 0;

    CPiece * tmp = board.getPiece(x, y);

    if (!sidestep) {
        if (tmp != NULL) {
            return 1;
        } else {
            moveList.add(x, y);
            return 0;
        }
    }

    // is sidestep

    if (tmp == NULL)
        return 1;

    else if (isFriendPiece(tmp)) {
        return 1;
    } else {
        moveList.add(x, y, board.getPiece(x, y));
        return 0;
    }

}
