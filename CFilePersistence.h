#ifndef CFILEPERSISTENCE_H
#define	CFILEPERSISTENCE_H

#include "CPersistence.h"
#include "TGameLoad.h"

/**
 * Subclass of CPersistence implementing its save and load operation on a file 
 */
class CFilePersistence : public CPersistence {
public:
    CFilePersistence();
    CFilePersistence(CGameSession * gamePtr);
    /**
     * Saves a game to a file specified by user
     */
    virtual void save() const;
    /**
     * Loads a game from a given file
     * @param filename File to be loaded
     * @return bool Success or failure of the load 
     */
    virtual bool load(const string & filename);
    
private:
    
    TGameLoad tLoad;    ///< An aid structure containing temporary data during a game load

    friend class CLoadGameMenu;
};



#endif	/* CFILEPERSISTENCE_H */

