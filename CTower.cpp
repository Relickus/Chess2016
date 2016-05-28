
#include "CTower.h"

CTower::CTower() {
    name = TOWER;
    isLongRunner = true;

    moveList.reserve(15);

}

CTower::~CTower() {

}

CTower::CTower(COLOR col) : CPiece(col) {
    name = TOWER;
    isLongRunner = true;

    moveList.reserve(15);

}
//
//void CTower::printPiece() const{
//        
//}

MoveList & CTower::getLegalMoves(const CBoard & board) {

    moveList.clear();

    //up

    int newX = getX();
    int newY = getY();

    for (int y = 0; newY < 8; y++) {

        if (checkField(newX, newY, board) == 1)
            break;

        newY = newY + y;
    }

    // down

    newX = getX();
    newY = getY();

    for (int y = 0; newY >= 0; y--) {

        if (checkField(newX, newY, board) == 1)
            break;

        newY = newY + y;
    }

    //left

    newX = getX();
    newY = getY();

    for (int x = 0; newX < 8; x++) {

        if (checkField(newX, newY, board) == 1)
            break;

        newX = newX + x;
    }

    //right

    newX = getX();
    newY = getY();

    for (int x = 0; newX >= 0; x--) {

        if (checkField(newX, newY, board) == 1)
            break;

        newX = newX + x;
    }


    return moveList;

}
