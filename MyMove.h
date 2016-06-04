#ifndef MOVE_H
#define	MOVE_H

#include <iostream>

using namespace std;

class CPiece;

struct MyMove{
    
    MyMove();
    MyMove(const MyMove & oth);
    MyMove(const string & movestr);
    MyMove(int tX, int tY,int frX=-1,int frY=-1);       // POZOR, nejdrive TO , pak FROM souradnice
    ~MyMove();
    bool isFicture() const;
    
    int fromX;
    int fromY;
    int toX;
    int toY;
    CPiece * figure;
};


#endif	/* MOVE_H */

