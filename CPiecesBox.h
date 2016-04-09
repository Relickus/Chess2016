#ifndef CPIECESBOX_H
#define	CPIECESBOX_H

#include "CPiece.h"


//   K VYMAZANI

class CPiecesBox {
public:
    CPiecesBox();
    CPiecesBox(const CPiecesBox& orig);
    virtual ~CPiecesBox();
private:
    
    CPiece * piecesBox[32];

};


#endif	/* CPIECESBOX_H */

