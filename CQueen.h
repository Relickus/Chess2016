#ifndef CQUEEN_H
#define	CQUEEN_H

class CQueen : public CPiece{
public:
    CQueen();
    CQueen(COLOR color);
    CQueen(const CQueen& orig);
    virtual ~CQueen();
    

    void printPiece() const;

private:

};



#endif	/* CQUEEN_H */

