#ifndef CSLOT_H
#define	CSLOT_H

class CPiece;

class CSlot {
public:
    CSlot();
    CSlot(CPiece * &);
    virtual ~CSlot();
    
    CPiece * getHeldPiece() const;
    void setHeldPiece(CPiece * p);
    void setValue(int v);
    int getValue() const;
    //void acceptVisitor(const CVisitor & v) const;

private:
    
    CPiece  * heldPiece;
    int value;
};


#endif	/* CSLOT_H */

