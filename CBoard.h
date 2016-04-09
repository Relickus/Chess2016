
#ifndef CBOARD_H
#define	CBOARD_H
#include "CSlot.h"

class CBoard {
public:
    CBoard();
    CBoard(const CBoard& orig);
    virtual ~CBoard();
    
    void printBoard() const;
private:
    
    CSlot slotsArr[8][8];
    const int width;
    const int height;
    
};


#endif	/* CBOARD_H */

