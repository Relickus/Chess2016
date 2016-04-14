#ifndef CABSTRACTCMENUSCREEN_H
#define	CABSTRACTCMENUSCREEN_H

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class CAbstractMenuScreen {
public:
    CAbstractMenuScreen();
    CAbstractMenuScreen(const CAbstractMenuScreen& orig);
    virtual ~CAbstractMenuScreen();
    
    void show() const;
    void printMenuItem(int i) const;
    
protected:
        
    string menuItems[5];

};


// KAZDY jednotlivy menu by mohlo mit nejakej CAbstractMenuScreen * next a *previous ukazatele kde si drzi jaky 
// menu ma jit po nich/pred nima a kdyz zavolam treba aktualni_menu->getNextMenu(),
//tak vrati treba instanci toho next menu a vsechno se to bude davat do CAbstractMenuScreen * aby se uplatnil Polymorf


#endif	/* CABSTRACTCMENUSCREEN_H */

