#ifndef MOVELIST_H
#define	MOVELIST_H

#include <vector>
#include <iostream>
#include "MyMove.h"


class CPiece;

using namespace std;


/**
 * Kontejner na tahy  
 */
class MoveList {
public:
    /**
     * 
     * @param MAXMOVES initial length of the inner vector to reserve
     */
    MoveList(int MAXMOVES=30);    
    virtual ~MoveList();
    
    /**
     * Adds a move given explicitly by parameters
     * @param x A destination row of the move
     * @param y A destination column of the move
     * @param fx An origin row of the move
     * @param fy An origin column of the move
     * @param tmp A figure taken by the move
     */
    void add(int x,int y,int fx,int fy,CPiece * tmp);   
    /**
     *Adds a move given by MyMove object
     */
    void add(MyMove move,CPiece * tmp = NULL);  
    /**
     * Checks whether the list of moves is empty
     */
    bool isEmpty() const;
    /**
     * Clears the list of moves
     */
    void clear();
    void reserve(int x);
    /**
     * Checks whether the list of moves contains a move given by parameter
     * @param move Given move
     */
    bool contains(const MyMove& move) const;
    /**
     * Concatenates the list of moves with another list
     * @param list Given reference to the list of moves
     */
    void concat(const MoveList & list);
    /**
     * Returns a move to a given position in the list of moves
     * @param idx index of the move
     * @return Move to a given position in the list of moves
     */
    MyMove getMove(int idx) const;
    /**
     * Returns size of the list of moves
     * @return size_t size of the list of moves
     */
    size_t size() const;
    
    vector<MyMove> moveVec;
    int numMoves;
    
    /**
     * Prints whole list of moves
     */
    void print() const;
};



#endif	/* MOVELIST_H */

