#ifndef CABSTRACTCMENUSCREEN_H
#define	CABSTRACTCMENUSCREEN_H

#include <iostream>

#define MAXITEMS 5

class CController;

using namespace std;

class CAbstractMenuScreen {
public:
    CAbstractMenuScreen(CAbstractMenuScreen * prPar=NULL);
    virtual ~CAbstractMenuScreen();
    
    virtual int readInput();
    virtual void show() const;
    void printMenuItem(int i) const;
    virtual void setNextMenu() = 0;
    virtual void setStuff(CController * ctrler) = 0;

    
    CAbstractMenuScreen * nextMenu;
    CAbstractMenuScreen * prevMenu;
    
protected:
        
    int getChoice() const;
    bool validChoice(int i) const;
    void setNumMenuItems();
    void showTitle() const;
    
    string menuItems[MAXITEMS];
    int numItems;
    int chosenOption;
    string title;
};

#endif	/* CABSTRACTCMENUSCREEN_H */

