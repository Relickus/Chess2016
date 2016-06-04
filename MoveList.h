#ifndef MOVELIST_H
#define	MOVELIST_H

#include <vector>
#include <iostream>
#include "MyMove.h"
class CPiece;

using namespace std;

class MoveList {
public:
    MoveList(int MAXMOVES=30);    
    virtual ~MoveList();
    
    void add(int x,int y,int fx,int fy);    
    void add(MyMove move);    
    bool isEmpty() const;
    void clear();
    void reserve(int x);
    bool contains(const MyMove& move) const;
    void concat(const MoveList & list);
    MyMove getMove(int idx) const;
    int size() const;
    
    vector<MyMove> moveVec;
    int numMoves;
    
    void print() const;
};



#endif	/* MOVELIST_H */

