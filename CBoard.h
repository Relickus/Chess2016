
#ifndef CBOARD_H
#define	CBOARD_H
#include "COLOR.h"
#include "CSlot.h"

class CGameSession;
class CPiece;
class CKing;
class CSlot;
class MoveList;
class MyMove;

using namespace std;

class CBoard {
    
    static void translateMove(MyMove & move);
    
public:
    CBoard();
    ~CBoard();
    CBoard(const CBoard & oth);
    void copy(const CBoard & oth);
    
    void printBoard() const;
    void printDebug() const;
    void printRotate() const;
    void printPossibleMoves(const MoveList & list) const;
    
    void initBoard(const CGameSession * gameSess);    
    CPiece * getPiece(int x, int y) const;
    bool outOfBoard(int x,int y) const;
    void setField(int row, int col, CPiece * pc);    
    void swapFigures(int r1,int c1, int r2,int c2);
    void rotateBoard();
    void moveFigure(const MyMove & move);
    int getSlotValue(int x,int y) const;
    bool tryMove(const MyMove & move,const CGameSession & gS) const;
    CKing * findKing(COLOR col) const;

    
    //bool fieldChecked(int x, int y, CPiece * playerspiece) const;
        // - lepsi bude zkusit tahnout kralem a zavolat king->isChecked na novym policku
    
    
    int INIT_ROW_UP;
    int INIT_ROW_DOWN;

    int LAST_ROW_UP;
    int LAST_ROW_DOWN;
    
private:
    
    void createPieces(COLOR colorUp);
    void promotePawn(const MyMove & move);
    
    CSlot slotsArr[8][8];
    const int width;
    const int height;
    
    
};


#endif	/* CBOARD_H */

