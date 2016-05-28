#include <string>

#include "CPiece.h"
#include "AllExceptions.h"

#include "MoveList.h"

using namespace std;
//
//void CPiece::acceptVisitor(const CVisitor & v) const{
//        
//    v.printPiece(this);
//}

CPiece::CPiece() {

}

CPiece::CPiece(COLOR col) : color(col) {

}

CPiece::~CPiece() {

}

bool CPiece::moveDown() {

    if (yPos <= 0)
        throw MoveOutOfBoardException();

    --yPos;

    return true;
}

bool CPiece::moveUp() {

    if (yPos >= 7)
        throw MoveOutOfBoardException();

    ++yPos;

    return true;
}

bool CPiece::moveLeft() {

    if (xPos <= 0)
        throw MoveOutOfBoardException();

    --xPos;

    return true;
}

bool CPiece::moveRight() {

    if (xPos >= 7)
        throw MoveOutOfBoardException();

    ++xPos;

    return true;
}

bool CPiece::moveDown(unsigned int by) {

    if (yPos - by < 0)
        throw MoveOutOfBoardException();

    yPos -= by;

    return true;
}

bool CPiece::moveUp(unsigned int by) {

    if (yPos + by > 7)
        throw MoveOutOfBoardException();

    yPos += by;

    return true;
}

bool CPiece::moveLeft(unsigned int by) {

    if (xPos - by < 0)
        throw MoveOutOfBoardException();

    xPos -= by;

    return true;
}

bool CPiece::moveRight(unsigned int by) {

    if (xPos + by > 7)
        throw MoveOutOfBoardException();

    xPos += by;

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
        cout << (char) tolower(getName());
    else
        cout << (char) getName();
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

int CPiece::getX() const {
    return xPos;
}

int CPiece::getY() const {
    return yPos;
}

bool CPiece::isFriendPiece(CPiece * tmp) const {

    return this->getColor() == tmp->getColor();
}

int CPiece::checkField(int x, int y, const CBoard & board) {

    if (y == getY() && x == getX())
        return 0;

    CPiece * tmp = board.getPiece(x, y);

    if (tmp != NULL) {

        if (isFriendPiece(tmp)) { // friend piece
            return 1;
        } else {
            moveList.add(x, y, board.getPiece(x, y));
            return 1;
        }
    } else {
        moveList.add(x, y);
    }

    return 0;
}