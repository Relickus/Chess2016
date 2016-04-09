#ifndef CKNIGHT_H
#define	CKNIGHT_H

class CKnight : public CPiece{
public:
    CKnight();
    CKnight(const CKnight& orig);
    virtual ~CKnight();
    

    void printPiece() const;

private:

};



#endif	/* CKNIGHT_H */

