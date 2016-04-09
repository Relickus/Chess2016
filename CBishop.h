#ifndef CBISHOP_H
#define	CBISHOP_H

class CBishop : public CPiece {
public:
    CBishop();
    CBishop(const CBishop& orig);
    virtual ~CBishop();
    

    void printPiece() const;


private:

};



#endif	/* CBISHOP_H */

