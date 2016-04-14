#ifndef CKING_H
#define	CKING_H

#include "CPiece.h"
#include "COLOR.h"

class CKing : public CPiece{
public:
    CKing();
    CKing(COLOR);
    CKing(const CKing& orig);
    virtual ~CKing();
    
    bool isChecked() const;

    void printPiece() const;

private:

};



#endif	/* CKING_H */

