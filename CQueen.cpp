
#include "CQueen.h"
#include "CPiece.h"

CQueen::CQueen() {
    name = QUEEN;
    isLongRunner = true;

    moveList.reserve(30);

}

CQueen::~CQueen() {

}

CQueen::CQueen(COLOR col) : CPiece(col) {

    name = QUEEN;
    isLongRunner = true;

    moveList.reserve(30);

}

//void CQueen::printPiece() const{
//        
//}

MoveList & CQueen::getLegalMoves(const CBoard & board) {

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

    //up left

    newX = getX();
    newY = getY();

    for (int y = 0, x = 0; newX >= 0 && newY < 8; y++, x--) {

        if (checkField(newX, newY, board) == 1)
            break;

        newX = newX + x;
        newY = newY + y;

    }

    // up right

    newX = getX();
    newY = getY();

    for (int y = 0, x = 0; newX < 8 && newY < 8; y++, x++) {

        if (checkField(newX, newY, board) == 1)
            break;

        newX = newX + x;
        newY = newY + y;
    }

    //down left

    newX = getX();
    newY = getY();

    for (int y = 0, x = 0; newX >= 0 && newY >= 0; y--, x--) {

        if (checkField(newX, newY, board) == 1)
            break;

        newX = newX + x;
        newY = newY + y;
    }

    //down right

    newX = getX();
    newY = getY();

    for (int y = 0, x = 0; newX < 8 && newY >= 0; y--, x++) {

        if (checkField(newX, newY, board) == 1)
            break;

        newX = newX + x;
        newY = newY + y;
    }


    return moveList;


}
