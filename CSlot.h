#ifndef CSLOT_H
#define	CSLOT_H

class CPiece;

/**
 * Class reprezenting a slot of a chessboard
 */
class CSlot {
public:
    CSlot();
    CSlot(CPiece * &);
    virtual ~CSlot();    
    /**
     * Returns a figure on the slot
     * @return Figure on the slot or NULL
     */
    CPiece * getHeldPiece() const;
    /**
     * Sets given figure to the slot
     * @param p pointer to the figure
     */
    void setHeldPiece(CPiece * p);
    /**
     * Sets a value of the slot
     * @param v hodnota
     */
    void setValue(int v);
    /**
     * Gets a value of the slot
     * @return int Value of the slot
     */
    int getValue() const;
    
private:
    
    CPiece  * heldPiece;    ///< Figure on the slot
    int value;  ///< Value of the slot
};


#endif	/* CSLOT_H */

