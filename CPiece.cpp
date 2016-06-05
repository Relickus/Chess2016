#include <string>

#include "CPiece.h"
#include "AllExceptions.h"

#include "CPawn.h"
#include "CBishop.h"
#include "CKnight.h"
#include "CTower.h"
#include "CKing.h"
#include "CQueen.h"

using namespace std;
//
//void CPiece::acceptVisitor(const CVisitor & v) const{
//        
//    v.printPiece(this);
//}

CPiece::CPiece() {

}

CPiece::CPiece(COLOR clr, int row, int col) : color(clr), rowPos(row), colPos(col) {

}

CPiece::~CPiece() {

}

bool CPiece::equals(FIGURENAME fig) const{
     return tolower(getName()) == tolower(fig);
}

bool CPiece::moveDown() {

    if (colPos <= 0)
        throw MoveOutOfBoardException();

    --colPos;

    return true;
}

bool CPiece::moveUp() {

    if (colPos >= 7)
        throw MoveOutOfBoardException();

    ++colPos;

    return true;
}

bool CPiece::moveLeft() {

    if (rowPos <= 0)
        throw MoveOutOfBoardException();

    --rowPos;

    return true;
}

bool CPiece::moveRight() {

    if (rowPos >= 7)
        throw MoveOutOfBoardException();

    ++rowPos;

    return true;
}

bool CPiece::moveDown(unsigned int by) {

    if (colPos - by < 0)
        throw MoveOutOfBoardException();

    colPos -= by;

    return true;
}

bool CPiece::moveUp(unsigned int by) {

    if (colPos + by > 7)
        throw MoveOutOfBoardException();

    colPos += by;

    return true;
}

bool CPiece::moveLeft(unsigned int by) {

    if (rowPos - by < 0)
        throw MoveOutOfBoardException();

    rowPos -= by;

    return true;
}

bool CPiece::moveRight(unsigned int by) {

    if (rowPos + by > 7)
        throw MoveOutOfBoardException();

    rowPos += by;

    return true;
}

FIGURENAME CPiece::getName() const {
    return name;
}

COLOR CPiece::getColor() const {
    return color;
}

void CPiece::printPiece() const {

    if (color == WHITE)
        cout << (char) toupper(getName());
    else
        cout << (char) tolower(getName());
}

//static CPiece * CPiece::getPieceByLetter(char letter){
//    
//        COLOR tmpcol;
//        if(islower(letter)){
//            tmpcol = BLACK;
//            letter = toupper(letter);
//        }
//        else 
//            tmpcol = WHITE;
//        
//        switch(letter){        
//            case(KING):
//                return new CKing(tmpcol);
//            case(QUEEN):
//                return new CQueen(tmpcol);
//            case(BISHOP):
//                return new CBishop(tmpcol);
//            case(PAWN):
//                return new CPawn(tmpcol);
//            case(TOWER):
//                return new CTower(tmpcol);
//            case(KNIGHT):
//                return new CKnight(tmpcol);            
//        }    
//}

int CPiece::getRow() const {
    return rowPos;
}

int CPiece::getCol() const {
    return colPos;
}

void CPiece::setRow(int r){
    rowPos = r;
}

void CPiece::setCol(int c){
    colPos = c;
}

bool CPiece::isFriendPiece(const CPiece * tmp) const {

    return this->getColor() == tmp->getColor();
}

bool CPiece::isFriendPiece(COLOR col) const {

    return this->getColor() == col;
}


int CPiece::checkField(int x, int y, const CBoard & board) {

    if (y == getCol() && x == getRow())
        return 0;

    CPiece * tmp = board.getPiece(x, y);

    if (tmp != NULL) {

        if (isFriendPiece(tmp)) { // friend piece
            return 1;
        } else {
            moveList.add(x, y,rowPos,colPos,tmp);
            return 1;
        }
    } else {
        moveList.add(x, y,rowPos,colPos,NULL);
    }

    return 0;
}

bool CPiece::validLetter(char c){
    
    if(c == '#')
        return true;
    
    char tmp = toupper(c);
    
    switch(tmp){
        case(PAWN):
        case(TOWER):
        case(QUEEN):
        case(KNIGHT):
        case(BISHOP):
        case(KING):
            return true;
            
        default : 
            return false;    
    }
    
}

 CPiece * CPiece::getPieceByLetter(char c,int row,int col){
     
     if(!CPiece::validLetter(c))
         throw InvalidFileCharacterException();
     
     COLOR clr;
     
     if(islower(c))
         clr = BLACK;
     else 
         clr = WHITE;
     
     
     switch(toupper(c)){
         
         case('#'):     // empty field             
             return NULL;
         
         case(PAWN):
             return new CPawn(clr,row,col);
         
         case(BISHOP):
             return new CBishop(clr,row,col);
         
         case(KNIGHT):
             return new CKnight(clr,row,col);
         
         case(TOWER):
             return new CTower(clr,row,col);
         
         case(QUEEN):
             return new CQueen(clr,row,col);
         
         case(KING):
             return new CKing(clr,row,col);         
     }
     
 }

 
 bool CPiece::moveTo(const MyMove & move, CBoard & board ){
     
     
     board.moveFigure(move);
            
     return true;
 }
 int CPiece::getValue() const {
     return value;
}
 