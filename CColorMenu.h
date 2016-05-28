#ifndef CCOLORMENU_H
#define	CCOLORMENU_H

#include "CAbstractMenuScreen.h"

class CColorMenu : public CAbstractMenuScreen{
public:
    CColorMenu(CAbstractMenuScreen * prPar=NULL);
    CColorMenu(const CColorMenu& orig);
    virtual ~CColorMenu();
    virtual void setNextMenu();
    virtual void setStuff(CController * ctrler);



    
private:

};


#endif	/* CCOLORMENU_H */

