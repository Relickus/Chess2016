#ifndef CDIFFICULTYMENU_H
#define	CDIFFICULTYMENU_H

#include "CAbstractMenuScreen.h"

class CDifficultyMenu : public CAbstractMenuScreen{
public:
    CDifficultyMenu(CAbstractMenuScreen * prPar=NULL);
    virtual ~CDifficultyMenu();
    virtual void setNextMenu();

    virtual void setStuff(CController * ctrler);

};



#endif	/* CDIFFICULTYMENU_H */

