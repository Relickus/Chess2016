
//#include "CPiece.h"
class CPiece;
#include "MoveList.h"
#include "CPiece.h"

MoveList::MoveList(int MAXMOVES) : numMoves(0){
    
    moveVec.reserve(MAXMOVES);
    moveVec.clear();
}

void MoveList::add(int x, int y, CPiece * takenpiece){
    
   moveVec.push_back( MyMove(x,y,takenpiece) ); 
    numMoves++;
}

bool MoveList::isEmpty() const{
    return numMoves==0;
}

void MoveList::clear(){
    numMoves=0;
    moveVec.clear();
}

void MoveList::reserve(int x){
    moveVec.reserve(x);
}

bool MoveList::contains(const MyMove& move) const {

//    auto it = find(moveVec.begin(),moveVec.end(),move);
   // if(it != moveVec.end())
    //    return true;
    
    return false;    
}

MoveList::~MoveList() {

}
