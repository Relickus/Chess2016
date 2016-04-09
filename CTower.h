#ifndef CTOWER_H
#define	CTOWER_H

class CTower : public CPiece{
public:
    CTower();
    CTower(const CTower& orig);
    virtual ~CTower();
    

    void printPiece() const;

private:

};



#endif	/* CTOWER_H */

