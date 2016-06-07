
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
public:
    CBoard();
    virtual ~CBoard();
    CBoard(const CBoard & oth);
    
    void printBoard() const;
    void printDebug() const;
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
    bool tryMove(const MyMove & move,CGameSession & gS) const;
    void undoMove(MyMove & move,CGameSession & gS) const;
    CKing * findKing(COLOR col) const;

    
    //bool fieldChecked(int x, int y, CPiece * playerspiece) const;
        // - lepsi bude zkusit tahnout kralem a zavolat king->isChecked na novym policku
    
    
    int INIT_ROW_UP;
    int INIT_ROW_DOWN;

    int LAST_ROW_UP;
    int LAST_ROW_DOWN;
    
private:
    
    void createPieces(COLOR colorUp);
    
    CSlot slotsArr[8][8];
    const int width;
    const int height;
    
    
};


#endif	/* CBOARD_H */

