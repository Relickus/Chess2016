
#include "CQueen.h"
#include "CPiece.h"
#include "CGameSession.h"


CQueen::CQueen() {
    name = QUEEN;
    

    moveList.reserve(30);
    value = 10;

}

CQueen::~CQueen() {

}

CQueen::CQueen(COLOR clr , int row, int col) : CPiece(clr,row,col) {

    name = QUEEN;
    

    moveList.reserve(30);
    value = 10;

}

CMoveList & CQueen::getLegalMoves(const CGameSession & gS) {

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

   //up left

    newRow = getRow();
    newCol = getCol();

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

CPiece* CQueen::copyPiece(const CPiece * pcs) const{
    return new CQueen(pcs->getColor(),pcs->getRow(),pcs->getCol());
}