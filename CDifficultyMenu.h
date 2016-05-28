#ifndef CDIFFICULTYMENU_H
#define	CDIFFICULTYMENU_H

#include "CAbstractMenuScreen.h"

class CDifficultyMenu : public CAbstractMenuScreen{
public:
    CDifficultyMenu(CAbstractMenuScreen * prPar=NULL);
    CDifficultyMenu(const CDifficultyMenu& orig);
    virtual ~CDifficultyMenu();
    virtual void setNextMenu();

    virtual void setStuff(CController * ctrler);

private:

};



#endif	/* CDIFFICULTYMENU_H */

