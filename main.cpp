/**
* @file main.cpp
* @author V. Mach
*
*
*/

#include "CController.h"
#include "CPiece.h"
#include "CKing.h"

using namespace std;

int main() {
        
    CController * c = new CController();

    c->showMenus();    
    c->startGame();
    
    delete c;
    return 0;
}

