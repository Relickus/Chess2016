
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

MoveList & CKnight::getLegalMoves(const CBoard & board) {

    moveList.clear();

    //up left

    int newRow = getRow() + 2;
    int newCol = getCol() - 1;

    if (!board.outOfBoard(newRow, newCol))
        checkField(newRow, newCol, board);


    // up right

    newRow = getRow() + 2;
    newCol = getCol() + 1;

    if (!board.outOfBoard(newRow, newCol))
        checkField(newRow, newCol, board);

    // down left

    newRow = getRow() - 1;
    newCol = getCol() - 2;

    if (!board.outOfBoard(newRow, newCol))
        checkField(newRow, newCol, board);

    // down right

    newRow = getRow() - 1;
    newCol = getCol() + 2;

    if (!board.outOfBoard(newRow, newCol))
        checkField(newRow, newCol, board);
    
    //up left 2
    
    newRow = getRow() + 1;
    newCol = getCol() - 2;

    if (!board.outOfBoard(newRow, newCol))
        checkField(newRow, newCol, board);
    
    //up right 2
    newRow = getRow() + 1;
    newCol = getCol() + 2;

    if (!board.outOfBoard(newRow, newCol))
        checkField(newRow, newCol, board);
    
    //down left 2
    newRow = getRow() - 2;
    newCol = getCol() - 1;

    if (!board.outOfBoard(newRow, newCol))
        checkField(newRow, newCol, board);
    
    //down right 2
    newRow = getRow() - 2;
    newCol = getCol() + 1;

    if (!board.outOfBoard(newRow, newCol))
        checkField(newRow, newCol, board);
    
    return moveList;
}
