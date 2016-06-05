#include "MyMove.h"


MyMove::MyMove() : figure (NULL) {

}
MyMove::MyMove(const string & movestr){

    fromX = movestr.at(0) - 48;
    fromY = movestr.at(1) - 49 - 48;
    
    toX = movestr.at(3) - 48;
    toY = movestr.at(4) - 49 - 48;
   
    figure = NULL;  // FIX !
}

MyMove::MyMove(int tX, int tY, int frX/*=-1*/, int frY/*=-1*/ ,CPiece * tmp) : toX(tX), toY(tY),fromX(frX),fromY(frY), figure(tmp){
}

MyMove::~MyMove() {

}

MyMove::MyMove(const MyMove& oth){
    
    fromX = oth.fromX;
    fromY = oth.fromY;
    toX = oth.toX;
    toY = oth.toY;
    
    figure = oth.figure;
}

bool MyMove::isFicture() const{
    
    if(fromX == -1)
        return true;
    return false;
}