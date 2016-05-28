#include "CKing.h"
#include "CPiece.h"
#include "CBoard.h"

CKing::CKing() {
    name = KING;
    isLongRunner = false;

    moveList.reserve(10);

}

CKing::~CKing() {

}

CKing::CKing(COLOR col) : CPiece(col) {
    name = KING;
    isLongRunner = false;

    moveList.reserve(10);
}
//
//void CKing::printPiece() const{
//        
//}

MoveList & CKing::getLegalMoves(const CBoard & board) {

    moveList.clear();

    //up left

    int newX = getX() - 1;
    int newY = getY() + 1;

    this->checkField(newX, newY, board);

    // up right

    newX = getX() + 1;
    newY = getY() + 1;

    this->checkField(newX, newY, board);

    // down left

    newX = getX() - 1;
    newY = getY() - 1;

    this->checkField(newX, newY, board);

    // down right

    newX = getX() + 1;
    newY = getY() - 1;

    this->checkField(newX, newY, board);

    // up 

    newX = getX();
    newY = getY() + 1;

    this->checkField(newX, newY, board);
    // down

    newX = getX();
    newY = getY() - 1;

    this->checkField(newX, newY, board);
    // left

    newX = getX() - 1;
    newY = getY();

    this->checkField(newX, newY, board);
    // right

    newX = getX() + 1;
    newY = getY();

    this->checkField(newX, newY, board);


    return moveList;
}

int CKing::checkField(int x, int y, const CBoard& board) {

    if (board.outOfBoard(x, y))
        return 1;

    if (x == getX() && y == getY())
        return 0;

    CPiece * tmp = board.getPiece(x, y);

    if (tmp != NULL) {
        if (isFriendPiece(tmp)) {
            return 1;
        } else {
            // ....... VEZMI JI - LEGAL JEN POKUD SE NEDOSTANE DO SACHU                
            if (!board.fieldChecked(x,y,tmp)) {
                moveList.add(x, y, board.getPiece(x, y));
                return 1;
            } else {
                return 1;
            }
        }
    } else {
        moveList.add(x, y);
        return 1;
    }
}
