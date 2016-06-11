
#include <stdio.h>

#include "CBishop.h"
#include "CPiece.h"
#include "CGameSession.h"

CBishop::CBishop() {
    name = BISHOP;
    

    moveList.reserve(15);
    value = 3;

}

CBishop::~CBishop() {

}

CBishop::CBishop(COLOR clr, int row, int col) : CPiece(clr,row,col) {
    name = BISHOP;
    

    moveList.reserve(15);
    value = 3;

}

CMoveList & CBishop::getLegalMoves(const CGameSession & gS) {

    moveList.clear();

    //up left

    int newRow = getRow();
    int newCol = getCol();

    for (;newRow < 8 && newCol >= 0; newRow++, newCol--) {

        if (checkField(newRow, newCol, gS.getBoard()) == 1)
            break;
    }

    // up right

    newRow = getRow();
    newCol = getCol();

    for (;newRow < 8 && newCol < 8; newRow++, newCol++) {

        if (checkField(newRow, newCol, gS.getBoard()) == 1)
            break;
    }

    //down left

    newRow = getRow();
    newCol = getCol();

    for (; newRow >= 0 && newCol >= 0; newRow--, newCol--) {

        if (checkField(newRow, newCol, gS.getBoard()) == 1)
            break;
    }

    //down right

    newRow = getRow();
    newCol = getCol();

    for (;newRow >= 0 && newCol < 8; newRow--, newCol++) {

        if (checkField(newRow, newCol, gS.getBoard()) == 1)
            break;
    }


    return moveList;
}

CPiece* CBishop::copyPiece(const CPiece * pcs) const  {
    return new CBishop(pcs->getColor(),pcs->getRow(),pcs->getCol());
}
