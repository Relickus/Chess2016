#ifndef CINTELLIGENCE_H
#define	CINTELLIGENCE_H

#include "DIFFICULTY.h"


class CIntelligence {
public:
    CIntelligence();
    CIntelligence(DIFFICULTY d);
    virtual ~CIntelligence();
    void changeDifficulty(DIFFICULTY d);
    void think() const;
    
private:
    
    DIFFICULTY difficulty;
};




#endif	/* CINTELLIGENCE_H */

