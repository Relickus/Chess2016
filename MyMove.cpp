#include "MyMove.h"
#include "CPiece.h"
#include "CGameSession.h"


MyMove::MyMove() : figure (NULL) {

}
MyMove::MyMove(const string & movestr){

    fromX = movestr.at(0) - 48;
    fromY = movestr.at(1) - 49 - 48;
    
    toX = movestr.at(3) - 48;
    toY = movestr.at(4) - 49 - 48;
   
    figure = NULL;
}

MyMove::MyMove(const char* buffer){
      
    fromX = (int)(buffer[0]-48);
    fromY = (int)(buffer[1]-48);
    toX = (int)(buffer[2]-48);
    toY = (int)(buffer[3]-48);
    
    if(buffer[4] == '#')
        figure = NULL;
    
    // o napojeni figure se stara az teprve CRemotePlayer::getMove protoze tam znam podobu CBoard, tady ji neznam
}

MyMove::MyMove(int tX, int tY, int frX/*=-1*/, int frY/*=-1*/ ,CPiece * tmp/*=NULL*/) : fromX(frX),fromY(frY),toX(tX), toY(tY), figure(tmp){
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

void MyMove::printMove() const {
    cout<< "*** Protivnik tahne z ["<<fromX<<","<<fromY<<"] na ["<<toX<<","<<toY<<"]";
    if(figure != NULL){
        cout<<" a bere figurku: ";
        figure->printPiece(cout);
        cout << " !";
    }
        cout<<endl;
}

void MyMove::tocstring(char* buffer) const {

    
    buffer[0] = char(fromX+48);
    buffer[1] = char(fromY+48);
    buffer[2] = char(toX+48);
    buffer[3] = char(toY+48);
    
    char fig;
    
    if(figure == NULL){
        fig = '#';
    }
    else{        
        if(figure->getColor() == BLACK)
            fig = tolower(figure->getName());
        else
            fig = toupper(figure->getName());
    }
    
    buffer[4] = fig;
    buffer[5] = '\0';
}

void MyMove::rotateMove() {

    fromX = 7- fromX;
    fromY = 7- fromY;
    toX = 7- toX;
    toY = 7- toY;
}

bool MyMove::operator==(const MyMove& oth) const {
    return (fromX == oth.fromX) && (fromY == oth.fromY) && (toX == oth.toX) && (toY==oth.toY);
}
