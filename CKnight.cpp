
#include "CKnight.h"
#include "CPiece.h"

CKnight::CKnight() {
    name = KNIGHT;
    isLongRunner = false;

    moveList.reserve(5);
}

CKnight::~CKnight() {

}

CKnight::CKnight(COLOR col) : CPiece(col) {
    name = KNIGHT;
    isLongRunner = false;

    moveList.reserve(5);

}
//
//void CKnight::printPiece() const{
//        
//}

MoveList & CKnight::getLegalMoves(const CBoard & board) {

    moveList.clear();

    //up left

    int newX = getX() - 1;
    int newY = getY() + 2;

    if (!board.outOfBoard(newX, newY))
        checkField(newX, newY, board);


    // up right

    newX = getX() + 1;
    newY = getY() + 2;

    if (!board.outOfBoard(newX, newY))
        checkField(newX, newY, board);

    // down left

    newX = getX() - 1;
    newY = getY() - 2;

    if (!board.outOfBoard(newX, newY))
        checkField(newX, newY, board);

    // down right

    newX = getX() + 1;
    newY = getY() - 2;

    if (!board.outOfBoard(newX, newY))
        checkField(newX, newY, board);

    return moveList;
}
