#ifndef CMoveList_H
#define	CMoveList_H

#include <vector>
#include <iostream>
#include "CMyMove.h"


class CPiece;

using namespace std;


/**
 * Kontejner na tahy  
 */
class CMoveList {
public:
    /**
     * 
     * @param MAXMOVES initial length of the inner vector to reserve
     */
    CMoveList(int MAXMOVES=30);    
    virtual ~CMoveList();
    
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
     *Adds a move given by CMyMove object
     */
    void add(CMyMove move,CPiece * tmp = NULL);  
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
    bool contains(const CMyMove& move) const;
    /**
     * Concatenates the list of moves with another list
     * @param list Given reference to the list of moves
     */
    void concat(const CMoveList & list);
    /**
     * Returns a move to a given position in the list of moves
     * @param idx index of the move
     * @return Move to a given position in the list of moves
     */
    CMyMove getMove(int idx) const;
    /**
     * Returns size of the list of moves
     * @return size_t size of the list of moves
     */
    size_t size() const;
    
    vector<CMyMove> moveVec;
    int numMoves;
    
    /**
     * Prints whole list of moves
     */
    void print() const;
};



#endif	/* CMoveList_H */

