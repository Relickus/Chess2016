#ifndef CPIECE_H
#define	CPIECE_H

class CPiece {
public:
    CPiece();
    CPiece(const CPiece& orig);
    virtual ~CPiece();
    
    bool moveUp();
    bool moveDown();
    bool moveLeft();
    bool moveRight();
    
private:

    int xPos;
    int yPos;
    COLOR color;
};


#endif	/* CPIECE_H */

