#ifndef CABSTRACTCMENUSCREEN_H
#define	CABSTRACTCMENUSCREEN_H

#include <iostream>
#include <cstring>
#include <cstdlib>

#define MAXITEMS 5

class CController;

using namespace std;

class CAbstractMenuScreen {
public:
    CAbstractMenuScreen(CAbstractMenuScreen * prPar=NULL);
    CAbstractMenuScreen(const CAbstractMenuScreen& orig);
    virtual ~CAbstractMenuScreen();
    
    void show() const;
    void printMenuItem(int i) const;
    virtual int readInput();
    int getChoice() const;
    virtual void setNextMenu() = 0;
    virtual void setStuff(CController * ctrler) = 0;
    void showTitle() const;

    
    CAbstractMenuScreen * nextMenu;
    CAbstractMenuScreen * prevMenu;
    
protected:
        
    bool validChoice(int i) const;
    void setNumMenuItems();
    
    string menuItems[MAXITEMS];
    int numItems;
    int chosenOption;
    string title;
};


// KAZDY jednotlivy menu by mohlo mit nejakej CAbstractMenuScreen * next a *previous ukazatele kde si drzi jaky 
// menu ma jit po nich/pred nima a kdyz zavolam treba aktualni_menu->getNextMenu(),
//tak vrati treba instanci toho next menu a vsechno se to bude davat do CAbstractMenuScreen * aby se uplatnil Polymorf


#endif	/* CABSTRACTCMENUSCREEN_H */

