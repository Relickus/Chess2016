#include "CPiece.h"
#include "CVisitor.h"
#include "AllExceptions.h"

using namespace std;
//
//void CPiece::acceptVisitor(const CVisitor & v) const{
//        
//    v.printPiece(this);
//}

bool CPiece::moveDown(){
    
    if(yPos <= 0)
        throw MoveOutOfBoardException();
    
    --yPos;
    
    return true;
}

bool CPiece::moveUp(){
    
    if(yPos >= 7)
        throw MoveOutOfBoardException();
    
    ++yPos;
    
    return true;
}

bool CPiece::moveLeft(){
    
    if(xPos <= 0)
        throw MoveOutOfBoardException();
    
    --xPos;
    
    return true;
}

bool CPiece::moveRight(){
    
    if(xPos >= 7)
        throw MoveOutOfBoardException();
    
    ++xPos;
    
    return true;
}
bool CPiece::moveDown(unsigned int by){
    
    if(yPos - by < 0)
        throw MoveOutOfBoardException();
            
    yPos-=by;
    
    return true;
}

bool CPiece::moveUp(unsigned int by){
    
    if(yPos + by > 7)
        throw MoveOutOfBoardException();
    
    yPos+=by;
    
    return true;
}

bool CPiece::moveLeft(unsigned int by){
    
    if(xPos - by < 0)
        throw MoveOutOfBoardException();
    
    xPos-=by;
    
    return true;
}

bool CPiece::moveRight(unsigned int by){
    
    if(xPos + by > 7)
        throw MoveOutOfBoardException();
    
    xPos+=by;
    
    return true;
}

FIGURENAME CPiece::getName() const{            
    return name;
}

COLOR CPiece::getColor() const{            
    return color;
}