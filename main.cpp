#include <cstdlib>

#include "CController.h"
#include "CPiece.h"
#include "CKing.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
        
    CController * c = new CController();

    c->showMenus();
    c->startGame();
    
    CKing * k = dynamic_cast<CKing*>(c->getGameSess().gameBoard.getPiece(0,4));
    
    cout<<endl << k->getName();
    CBoard & b =c->getGameSess().gameBoard;
    
    cout << k->isChecked(b);
    
    delete c;
    return 0;
}

