#ifndef CKING_H
#define	CKING_H

class CKing : public CPiece{
public:
    CKing();
    CKing(const CKing& orig);
    virtual ~CKing();
    
    bool isChecked() const;

    void printPiece() const;

private:

};



#endif	/* CKING_H */

