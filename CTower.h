#ifndef CTOWER_H
#define	CTOWER_H

#include "COLOR.h"
#include "CPiece.h"

class CTower : public CPiece{
public:
    CTower();
    CTower(COLOR col);
    CTower(const CTower& orig);
    virtual ~CTower();
    

    void printPiece() const;

private:

};



#endif	/* CTOWER_H */

