#ifndef CCOMMAND_H
#define	CCOMMAND_H

#include "COMMAND.h"
#include "MyMove.h"
#include "CController.h"

class CGameSession;

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
    void surrenderQuery(CGameSession & gS) const;
    void checkQuery(CGameSession & gS) const;
    void tieQuery(CGameSession & gS) const;
    MyMove & getMoveRef();
    
    COMMAND command;
    
private:
    int x;
    int y;
    MyMove move;
    
    friend CController;
    
};



#endif	/* CCOMMAND_H */

