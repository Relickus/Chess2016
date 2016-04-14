#ifndef CSLOT_H
#define	CSLOT_H

#include "CPiece.h"

class CSlot {
public:
    CSlot();
    CSlot(CPiece * &);
    virtual ~CSlot();
    
    CPiece * getHeldPiece() const;
    void setHeldPiece(CPiece * p);
    //void acceptVisitor(const CVisitor & v) const;

private:
    
    CPiece  * heldPiece;

};


#endif	/* CSLOT_H */

