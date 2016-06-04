#ifndef CMULTIPLAYERHOSTMENU_H
#define	CMULTIPLAYERHOSTMENU_H

#include "CAbstractMenuScreen.h"


class CMultiplayerHostMenu : public CAbstractMenuScreen{
public:
    CMultiplayerHostMenu(CAbstractMenuScreen * prPar=NULL);
    CMultiplayerHostMenu(const CMultiplayerHostMenu& orig);
    virtual ~CMultiplayerHostMenu();

    virtual void setStuff(CController* ctrler);
    virtual void setNextMenu();
    virtual void show() const;




private:

};



#endif	/* CMULTIPLAYERHOSTMENU_H */

