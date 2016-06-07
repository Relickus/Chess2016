#ifndef CFILEPERSISTENCE_H
#define	CFILEPERSISTENCE_H

#include "CPersistence.h"
#include "TGameLoad.h"

class CFilePersistence : public CPersistence {
public:
    CFilePersistence();
    CFilePersistence(CGameSession * gamePtr);
    void save() const;
    virtual bool load(const string & filename);
    
private:
    
    TGameLoad tLoad;

    friend class CLoadGameMenu;
};



#endif	/* CFILEPERSISTENCE_H */

