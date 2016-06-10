#ifndef CABSTRACTCMENUSCREEN_H
#define	CABSTRACTCMENUSCREEN_H

#include <iostream>

#define MAXITEMS 5      ///< maximum number of items in single menu

class CController;

using namespace std;

/**
 *
 * Abstract parent class for menu classes
 * 
 */
class CAbstractMenuScreen {
public:
    /**
     *Initializes menu
     * 
     * @param Pointer to the previous menu
     */
    CAbstractMenuScreen(CAbstractMenuScreen * prPar=NULL);
    virtual ~CAbstractMenuScreen();
      
    /**
     * Reads input from user
     * 
     */
    virtual int readInput();
     /**
     *  Fisplays whole menu
     * 
     */
    virtual void show() const;
    /**
     *  Displays a single item from menu
     * 
     */
    void printMenuItem(int i) const;
    /**
     *  Sets pointer to next menu
     * 
     */
    virtual void setNextMenu() = 0;
    /**
     *  Sets whatever there is to be set from this menu that is needed for game initialization
     * 
     */
    virtual void setStuff(CController * ctrler) = 0;

    
    CAbstractMenuScreen * nextMenu;     ///< pointer to the next menu(NULL if it is the last menu before entering the game)
    CAbstractMenuScreen * prevMenu;     ///< pointer to the previous menu
    
protected:
     
    /**
     *  Returns index of the chosen option from this menu
     * @return int index of the chosen option
     */
    int getChoice() const;
       
    /**
     *  Checks if the given index is withing range of options in this menu 
     * @param int index of the chosen option
     * 
     */
    bool validChoice(int i) const;
        
    /**
     * Sets number of items in this menu
     * Note: Number of items in each menu differs.
     * 
     */
    void setNumMenuItems();
    /**
     *  Shows title of the current menu
     * 
     */
    void showTitle() const;
    
    string menuItems[MAXITEMS];     ///< array of items in the menu
    int numItems;                   ///< number of items in the menu
    int chosenOption;               ///<index of the option chosen by user
    string title;                   ///< title of current menu
};

#endif	/* CABSTRACTCMENUSCREEN_H */

