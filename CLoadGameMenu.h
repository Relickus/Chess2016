#ifndef CLOADGAMEMENU_H
#define	CLOADGAMEMENU_H

#include "CAbstractMenuScreen.h"
#include "CBoard.h"
#include "CFilePersistence.h"

class CLoadGameMenu : public CAbstractMenuScreen {
public:
    CLoadGameMenu(CAbstractMenuScreen * prPar=NULL);
    CLoadGameMenu(const CLoadGameMenu& orig);
    virtual ~CLoadGameMenu();
    virtual void setNextMenu();
    int readInput();
    void loadFromFile(const string & filename);
    bool confirmLoad();
    virtual void setStuff(CController* ctrler);
    bool findFile(const string & file) const;
    virtual void show() const;



private:
    
    string fileGame;
    CBoard tmpboard;
    char colorChar;
    COLOR tmpColor;
    COLOR tmpTurn;
    bool loadSuccessful;
    CFilePersistence * persistence;

};


#endif	/* CLOADGAMEMENU_H */

