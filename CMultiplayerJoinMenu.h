#ifndef CMULTIPLAYERJOINMENU_H
#define	CMULTIPLAYERJOINMENU_H

#include "CAbstractMenuScreen.h"


class CMultiplayerJoinMenu : public CAbstractMenuScreen{
public:
    CMultiplayerJoinMenu(CAbstractMenuScreen * prPar=NULL);
    CMultiplayerJoinMenu(const CMultiplayerJoinMenu& orig);
    virtual ~CMultiplayerJoinMenu();
    virtual void setNextMenu();
    int readInput();
    bool validIP(const string & ip) const;

    virtual void setStuff(CController* ctrler);


private:

    string IP;
};



#endif	/* CMULTIPLAYERJOINMENU_H */

