#ifndef CINTELLIGENCE_H
#define	CINTELLIGENCE_H

#include "DIFFICULTY.h"
#include "COpponent.h"


class CIntelligence : public COpponent {
public:
    CIntelligence();
    CIntelligence(DIFFICULTY d);
    virtual ~CIntelligence();
    void changeDifficulty(DIFFICULTY d);
    void think() const;
    virtual void makeMove() const;

    
private:
    
    DIFFICULTY difficulty;
};




#endif	/* CINTELLIGENCE_H */

