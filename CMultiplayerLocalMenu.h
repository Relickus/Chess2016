
#ifndef CMULTIPLAYERLOCALMENU_H
#define	CMULTIPLAYERLOCALMENU_H

#include "CAbstractMenuScreen.h"


class CMultiplayerLocalMenu : public CAbstractMenuScreen {
public:
    CMultiplayerLocalMenu(CAbstractMenuScreen * prPar=NULL);
    CMultiplayerLocalMenu(const CMultiplayerLocalMenu& orig);
    virtual ~CMultiplayerLocalMenu();
    virtual void setNextMenu();

private:

};


#endif	/* CMULTIPLAYERLOCALMENU_H */

