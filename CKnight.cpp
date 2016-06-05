
#include "CKnight.h"
#include "CPiece.h"

CKnight::CKnight() {
    name = KNIGHT;
    isLongRunner = false;

    moveList.reserve(5);
    value = 5;
}

CKnight::~CKnight() {

}

CKnight::CKnight(COLOR clr , int row, int col) : CPiece(clr,row,col) {
    name = KNIGHT;
    isLongRunner = false;

    moveList.reserve(5);
    value = 5;

}
//
//void CKnight::printPiece() const{
//        
//}

MoveList & CKnight::getLegalMoves(const CGameSession & gS) {

    moveList.clear();

    //up left

    int newRow = getRow() + 2;
    int newCol = getCol() - 1;

    if (!gS.gameBoard.outOfBoard(newRow, newCol))
        checkField(newRow, newCol, gS.gameBoard);


    // up right

    newRow = getRow() + 2;
    newCol = getCol() + 1;

    if (!gS.gameBoard.outOfBoard(newRow, newCol))
        checkField(newRow, newCol, gS.gameBoard);

    // down left

    newRow = getRow() - 1;
    newCol = getCol() - 2;

    if (!gS.gameBoard.outOfBoard(newRow, newCol))
        checkField(newRow, newCol, gS.gameBoard);

    // down right

    newRow = getRow() - 1;
    newCol = getCol() + 2;

    if (!gS.gameBoard.outOfBoard(newRow, newCol))
        checkField(newRow, newCol, gS.gameBoard);
    
    //up left 2
    
    newRow = getRow() + 1;
    newCol = getCol() - 2;

    if (!gS.gameBoard.outOfBoard(newRow, newCol))
        checkField(newRow, newCol, gS.gameBoard);
    
    //up right 2
    newRow = getRow() + 1;
    newCol = getCol() + 2;

    if (!gS.gameBoard.outOfBoard(newRow, newCol))
        checkField(newRow, newCol, gS.gameBoard);
    
    //down left 2
    newRow = getRow() - 2;
    newCol = getCol() - 1;

    if (!gS.gameBoard.outOfBoard(newRow, newCol))
        checkField(newRow, newCol, gS.gameBoard);
    
    //down right 2
    newRow = getRow() - 2;
    newCol = getCol() + 1;

    if (!gS.gameBoard.outOfBoard(newRow, newCol))
        checkField(newRow, newCol, gS.gameBoard);
    
    return moveList;
}

CPiece* CKnight::copyPiece(CPiece* pcs) {
    return new CKnight(pcs->getColor(),pcs->getRow(),pcs->getCol());
}