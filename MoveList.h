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
    
    void add(int x,int y,CPiece * takenpiece = NULL);    
    bool isEmpty() const;
    void clear();
    void reserve(int x);
    bool contains(const MyMove & move) const;
    
    vector<MyMove> moveVec;
    int numMoves;
};



#endif	/* MOVELIST_H */

