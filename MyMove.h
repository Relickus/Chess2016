#ifndef MOVE_H
#define	MOVE_H

#include <iostream>

using namespace std;

class CPiece;

struct MyMove{
    
    MyMove();
    MyMove(const MyMove & oth);
    MyMove(const string & movestr);
    MyMove(const char * buffer);
    bool operator==(const MyMove & oth) const;
    MyMove(int tX, int tY,int frX=-1,int frY=-1,CPiece * tmp=NULL);       // POZOR, nejdrive TO , pak FROM souradnice
    void rotateMove();
    void printMove() const;
    bool isFicture() const;
    void tocstring(char * buffer) const;
    void setFigure(CPiece * fig);
    
    int fromX;
    int fromY;
    int toX;
    int toY;
    CPiece * figure;
};


#endif	/* MOVE_H */

