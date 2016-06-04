
#ifndef CBOARD_H
#define	CBOARD_H
#include "CSlot.h"
#include "COLOR.h"
#include "AllExceptions.h"
#include "MoveList.h"

class CGameSession;

using namespace std;

class CBoard {
public:
    CBoard();
    CBoard(const CBoard& orig);
    virtual ~CBoard();
    
    void printBoard() const;
    void printRotate();
    static void translateMove(MyMove & move);
    void initBoard(const CGameSession * gameSess);    
    void printPossibleMoves(const MoveList & list) const;
    CPiece * getPiece(int x, int y) const;
    bool outOfBoard(int x,int y) const;
    void setField(int row, int col, CPiece * pc);
    
    void copy(CBoard & oth);
    void swapFigures(int r1,int c1, int r2,int c2);
    void rotateBoard();
    void moveFigure(const MyMove & move);
    void promotePawn(const MyMove & move);
    int getSlotValue(int x,int y) const;
    
    //bool fieldChecked(int x, int y, CPiece * playerspiece) const;
        // - lepsi bude zkusit tahnout kralem a zavolat king->isChecked na novym policku
    
    
    static const int INIT_ROW_UP = 6;
    static const int INIT_ROW_DOWN = 1;

    static const int LAST_ROW_UP = 0;
    static const int LAST_ROW_DOWN = 7;
    
private:
    
    void createPieces(COLOR colorUp);
    
    CSlot slotsArr[8][8];
    const int width;
    const int height;
    
    
};


#endif	/* CBOARD_H */

