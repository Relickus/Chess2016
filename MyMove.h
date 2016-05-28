#ifndef MOVE_H
#define	MOVE_H

#include <iostream>

class CPiece;

struct MyMove{
    
    MyMove();
    MyMove(int X, int Y, CPiece * takenfigure=NULL);
    ~MyMove();
    
    int x;
    int y;
    
    CPiece * takenFigure;
    
};


#endif	/* MOVE_H */

