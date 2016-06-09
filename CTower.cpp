
#include "CTower.h"
#include "CGameSession.h"


CTower::CTower() {
    name = TOWER;
    

    moveList.reserve(15);
    value = 5;
}

CTower::~CTower() {

}

CTower::CTower(COLOR clr , int row, int col) : CPiece(clr,row,col) {
    name = TOWER;
    

    moveList.reserve(15);
    value = 5;

}

MoveList & CTower::getLegalMoves(const CGameSession & gS) {

    moveList.clear();

     //up

    int newRow = getRow();
    int newCol = getCol();

    for (;newRow < 8; newRow++) {

        if (checkField(newRow, newCol, gS.getBoard()) == 1)
            break;

    }

    // down

    newRow = getRow();
    newCol = getCol();

    for (; newRow >= 0; newRow--) {

        if (checkField(newRow, newCol, gS.getBoard()) == 1)
            break;
    }

    //left

    newRow = getRow();
    newCol = getCol();

    for (;newCol >= 0; newCol--) {

        if (checkField(newRow, newCol, gS.getBoard()) == 1)
            break;
    }

    //right

    newRow = getRow();
    newCol = getCol();

    for (;newCol < 8; newCol++) {

        if (checkField(newRow, newCol, gS.getBoard()) == 1)
            break;
    }



    return moveList;

}

CPiece* CTower::copyPiece(const CPiece * pcs) const{
    return new CTower(pcs->getColor(),pcs->getRow(),pcs->getCol());
}