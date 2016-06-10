#ifndef CLOADGAMEMENU_H
#define	CLOADGAMEMENU_H

#include "CAbstractMenuScreen.h"
#include "CBoard.h"
#include "CFilePersistence.h"

/**
 * Subclass of CAbstractMenuScreen for loading a saved game
 */
class CLoadGameMenu : public CAbstractMenuScreen {
public:
     /**
     * @brief Initializes the menu
     * 
     * @param Pointer to the previous menu
     */
    CLoadGameMenu(CAbstractMenuScreen * prPar=NULL);
    virtual ~CLoadGameMenu();
    /**
     * @brief Sets pointer to next menu
     * 
     */
    virtual void setNextMenu();
    int readInput();
    /**
     * Calls for a game load from given file
     * @param filename Name of file with stored game 
     */
    void loadFromFile(const string & filename);
    /**
     * Asks user to confirm or deny a game load
     */
    bool confirmLoad();
       /**
     * @brief Sets whatever there is to be set from this menu that is needed for game initialization
     * 
     */
    virtual void setStuff(CController* ctrler);
    /**
     * Checks whether a given file exists
     * @param file Name of the file
     * @return bool if the file exists
     */
    bool findFile(const string & file) const;
    virtual void show() const;

private:
    
    string fileGame;    ///< name of the file loadede from
    bool loadSuccessful;    ///< was the load succesful?
    CFilePersistence * persistence; ///< pointer to an instance of persistence performing the save/load operations

};


#endif	/* CLOADGAMEMENU_H */

