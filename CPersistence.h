#ifndef CPERSISTENCE_H
#define	CPERSISTENCE_H

#include <iostream>

class CGameSession;

using namespace std;

class CPersistence {
public:
    CPersistence();
    CPersistence(CGameSession * b);
    virtual ~CPersistence();
    virtual void save() const = 0;
    virtual bool load(const string & filename) = 0;
    
protected:
    
    CGameSession * gamePtr;

};



#endif	/* CPERSISTENCE_H */

