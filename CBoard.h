
#ifndef CBOARD_H
#define	CBOARD_H
#include "CSlot.h"
#include "COLOR.h"

class CGameSession;

using namespace std;

class CBoard {
public:
    CBoard();
    CBoard(const CBoard& orig);
    virtual ~CBoard();
    
    void printBoard() const;
    void initBoard(const CGameSession * gameSess);    
    void printPossibleMoves(CPiece * pc) const;
    //void loadFromFile(const string & filename);
    CPiece * getPiece(int x, int y) const;
    bool outOfBoard(int x,int y) const;
    bool fieldChecked(int x, int y, CPiece * playerspiece) const;

private:
    
    void createPieces(COLOR colorUp);
    
    CSlot slotsArr[8][8];
    const int width;
    const int height;
    
};


#endif	/* CBOARD_H */

