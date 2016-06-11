
//#include "CPiece.h"
class CPiece;
#include "CMoveList.h"
#include "CPiece.h"

CMoveList::CMoveList(int MAXMOVES) : numMoves(0){
    
    moveVec.reserve(MAXMOVES);
    moveVec.clear();
}

void CMoveList::add(CMyMove move,CPiece * tmp){
    move.figure = tmp;
    moveVec.push_back(move);
    numMoves++;
}

void CMoveList::add(int x, int y,int fx,int fy,CPiece * tmp){
    
   moveVec.push_back( CMyMove(x,y,fx,fy,tmp) ); 
    numMoves++;
}

bool CMoveList::isEmpty() const{
    return numMoves==0;
}

void CMoveList::clear(){
    numMoves=0;
    moveVec.clear();
}

void CMoveList::reserve(int x){
    moveVec.reserve(x);
}

bool CMoveList::contains(const CMyMove& move) const {

    for(size_t i = 0; i < moveVec.size(); ++i){        
        if(moveVec.at(i).toX == move.toX && moveVec.at(i).toY == move.toY )
            return true;
    }
    
    return false;    
}

CMoveList::~CMoveList() {

}


void CMoveList::print() const{
    
    for(auto & i : moveVec){
        cout << "[" <<i.fromX<<","<<i.fromY<<"] -> [" << i.toX << ","<<i.toY<<"], ";
        if(i.figure==NULL)
            cout << "null";
        else
            i.figure->printPiece(cout);
        cout <<endl;
    }
}

void CMoveList::concat(const CMoveList& list) {

    for(size_t i = 0; i < list.moveVec.size(); ++i){
        add(list.getMove(i),list.getMove(i).figure);
    }
    numMoves = moveVec.size();
}

CMyMove CMoveList::getMove(int idx) const{
    
    return moveVec.at(idx);
}

size_t CMoveList::size() const {
    return moveVec.size();
}
