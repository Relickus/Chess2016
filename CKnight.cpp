
#include "CKnight.h"
#include "CPiece.h"
#include "CGameSession.h"

CKnight::CKnight() {
    name = KNIGHT;
    

    moveList.reserve(5);
    value = 5;
}

CKnight::~CKnight() {

}

CKnight::CKnight(COLOR clr , int row, int col) : CPiece(clr,row,col) {
    name = KNIGHT;
    

    moveList.reserve(5);
    value = 5;

}

CMoveList & CKnight::getLegalMoves(const CGameSession & gS) {

    moveList.clear();

    //up left

    int newRow = getRow() + 2;
    int newCol = getCol() - 1;

    if (!gS.getBoard().outOfBoard(newRow, newCol))
        checkField(newRow, newCol, gS.getBoard());


    // up right

    newRow = getRow() + 2;
    newCol = getCol() + 1;

    if (!gS.getBoard().outOfBoard(newRow, newCol))
        checkField(newRow, newCol, gS.getBoard());

    // down left

    newRow = getRow() - 1;
    newCol = getCol() - 2;

    if (!gS.getBoard().outOfBoard(newRow, newCol))
        checkField(newRow, newCol, gS.getBoard());

    // down right

    newRow = getRow() - 1;
    newCol = getCol() + 2;

    if (!gS.getBoard().outOfBoard(newRow, newCol))
        checkField(newRow, newCol, gS.getBoard());
    
    //up left 2
    
    newRow = getRow() + 1;
    newCol = getCol() - 2;

    if (!gS.getBoard().outOfBoard(newRow, newCol))
        checkField(newRow, newCol, gS.getBoard());
    
    //up right 2
    newRow = getRow() + 1;
    newCol = getCol() + 2;

    if (!gS.getBoard().outOfBoard(newRow, newCol))
        checkField(newRow, newCol, gS.getBoard());
    
    //down left 2
    newRow = getRow() - 2;
    newCol = getCol() - 1;

    if (!gS.getBoard().outOfBoard(newRow, newCol))
        checkField(newRow, newCol, gS.getBoard());
    
    //down right 2
    newRow = getRow() - 2;
    newCol = getCol() + 1;

    if (!gS.getBoard().outOfBoard(newRow, newCol))
        checkField(newRow, newCol, gS.getBoard());
    
    return moveList;
}

CPiece* CKnight::copyPiece(const CPiece * pcs) const{
    return new CKnight(pcs->getColor(),pcs->getRow(),pcs->getCol());
}