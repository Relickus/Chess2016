
#include <stdio.h>

#include "CBishop.h"
#include "CPiece.h"

CBishop::CBishop() {
    name = BISHOP;
    isLongRunner = true;

    moveList.reserve(15);
    value = 3;

}

CBishop::~CBishop() {

}

CBishop::CBishop(COLOR clr, int row, int col) : CPiece(clr,row,col) {
    name = BISHOP;
    isLongRunner = true;

    moveList.reserve(15);
    value = 3;

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
//    if(x == getRow() && y ==getCol())   // nesmi zustat na miste
//        return false;
//    
//    
//    if( abs(x-getRow()) != abs(y-getCol()) )    // pouze diagonalni tah toto splni
//        return false;
//    
//    
//    return true;
//}

MoveList & CBishop::getLegalMoves(const CBoard & board) {

    moveList.clear();

    //up left

    int newRow = getRow();
    int newCol = getCol();

    for (;newRow < 8 && newCol >= 0; newRow++, newCol--) {

        if (checkField(newRow, newCol, board) == 1)
            break;
    }

    // up right

    newRow = getRow();
    newCol = getCol();

    for (;newRow < 8 && newCol < 8; newRow++, newCol++) {

        if (checkField(newRow, newCol, board) == 1)
            break;
    }

    //down left

    newRow = getRow();
    newCol = getCol();

    for (; newRow >= 0 && newCol >= 0; newRow--, newCol--) {

        if (checkField(newRow, newCol, board) == 1)
            break;
    }

    //down right

    newRow = getRow();
    newCol = getCol();

    for (;newRow >= 0 && newCol < 8; newRow--, newCol++) {

        if (checkField(newRow, newCol, board) == 1)
            break;
    }


    return moveList;
}
