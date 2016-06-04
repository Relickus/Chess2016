
//#include "CPiece.h"
class CPiece;
#include "MoveList.h"
#include "CPiece.h"

MoveList::MoveList(int MAXMOVES) : numMoves(0){
    
    moveVec.reserve(MAXMOVES);
    moveVec.clear();
}

void MoveList::add(MyMove move,CPiece * tmp){
    moveVec.push_back(move);
    moveVec.rbegin()->figure = tmp;
    numMoves++;
}

void MoveList::add(int x, int y,int fx,int fy,CPiece * tmp){
    
   moveVec.push_back( MyMove(x,y,fx,fy) ); 
   moveVec.rbegin()->figure = tmp;
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

    for(size_t i = 0; i < moveVec.size(); ++i){        
        if(moveVec.at(i).toX == move.toX && moveVec.at(i).toY == move.toY )
            return true;
    }
    
    return false;    
}

MoveList::~MoveList() {

}


void MoveList::print() const{
    
    for(auto & i : moveVec){
        cout << "[" <<i.fromX<<","<<i.fromY<<"] -> [" << i.toX << ","<<i.toY<<"], ";
        if(i.figure==NULL)
            cout << "null" <<endl;
        else
            i.figure->printPiece();
    }
}

void MoveList::concat(const MoveList& list) {

    for(size_t i = 0; i < list.moveVec.size(); ++i){
        add(list.getMove(i));
    }
    numMoves = numMoves + list.numMoves;
}

MyMove MoveList::getMove(int idx) const{
    
    return moveVec.at(idx);
}

int MoveList::size() const {
    return moveVec.size();
}
