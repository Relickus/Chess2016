#ifndef CPERSISTENCE_H
#define	CPERSISTENCE_H

#include <iostream>

class CGameSession;

using namespace std;

class CPersistence {
public:
    CPersistence();
    virtual ~CPersistence();
    CPersistence(CGameSession * b);
    /**
     * abstract function to save current state of a game
     */
    virtual void save() const = 0;
    /**
     * abstract funtion to load a game from file
     * @param filename name of the file to read from
     */
    virtual bool load(const string & filename) = 0;
    
protected:
    
    CGameSession * gamePtr; ///< pointer to instance of a game 

};



#endif	/* CPERSISTENCE_H */

