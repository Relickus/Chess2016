
#include <stdio.h>

#include "CBishop.h"
#include "CPiece.h"

CBishop::CBishop() {
    name = BISHOP;
    isLongRunner = true;

    moveList.reserve(15);
}

CBishop::~CBishop() {

}

CBishop::CBishop(COLOR col) : CPiece(col) {
    name = BISHOP;
    isLongRunner = true;

    moveList.reserve(15);
}
//
//void CBishop::printPiece() const{
//        
//}
//
//bool CBishop::isLegalMove(int x, int y) const {
//
//    // smí jezdit jen sikmo do vsech stran
//    
//    if(x == getX() && y ==getY())   // nesmi zustat na miste
//        return false;
//    
//    
//    if( abs(x-getX()) != abs(y-getY()) )    // pouze diagonalni tah toto splni
//        return false;
//    
//    
//    return true;
//}

MoveList & CBishop::getLegalMoves(const CBoard & board) {

    moveList.clear();

    //up left

    int newX = getX();
    int newY = getY();

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
