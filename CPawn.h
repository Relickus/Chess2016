#ifndef CPAWN_H
#define	CPAWN_H

#include "CPiece.h"

class CPawn : public CPiece{
public:
    CPawn();
    CPawn(const CPawn& orig);
    virtual ~CPawn();
    
    void printPiece() const;
      

private:
    
    //bool promoteToQueen();    // - tohle by mel udelat CConstroller

};



#endif	/* CPAWN_H */

