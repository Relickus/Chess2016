#ifndef CCOMMAND_H
#define	CCOMMAND_H

#include "CCommand.h"
#include "CGameSession.h"
#include "COMMAND.h"
#include "MyMove.h"
#include "CPersistence.h"

using namespace std;

class CCommand {
public:
    CCommand();
    CCommand(const MyMove & mv);
    CCommand(COMMAND com);
    void makeCommand(const string & str);
    void executeCommand(CGameSession & gS);

    void movesQuery(CGameSession & gS) const;
    void exitQuery(CGameSession & gS) const;
    void saveQuery(CGameSession & gS) const;
    void rotateQuery(CGameSession & gS) const;
    void makeMoveQuery(CGameSession & gS) const;     

    
    COMMAND command;
    
private:
    int x;
    int y;
    MyMove move;

};



#endif	/* CCOMMAND_H */

