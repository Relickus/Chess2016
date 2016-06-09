#include <string>

#include "CPiece.h"
#include "AllExceptions.h"
#include "CGameSession.h"

#include "CPawn.h"
#include "CBishop.h"
#include "CKnight.h"
#include "CTower.h"
#include "CKing.h"
#include "CQueen.h"

#include "CBoard.h"

using namespace std;

CPiece::CPiece() : rowPos(-1),colPos(-1){

}

CPiece::CPiece(COLOR clr, int row, int col) : color(clr), rowPos(row), colPos(col) {

}

CPiece::~CPiece() {

}

bool CPiece::equals(FIGURENAME fig) const{
     return tolower(getName()) == tolower(fig);
}


FIGURENAME CPiece::getName() const {
    return name;
}

COLOR CPiece::getColor() const {
    return color;
}

void CPiece::printPiece(ostream & os) const {

    if (color == WHITE)
        os << (char) toupper(getName());
    else
        os << (char) tolower(getName());
}

int CPiece::getRow() const {
    if(rowPos >7 || rowPos < 0)
        cout << "SPATNEJ ROW"<<endl;
    return rowPos;
}

int CPiece::getCol() const {
    if(colPos >7 || colPos < 0)
        cout << "SPATNEJ COL"<<endl;
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
 void CPiece::setValue(int val) {
     value = val;
}
