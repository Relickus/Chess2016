#include <cstdlib>

#include "CController.h"
#include "CPiece.h"
#include "CKing.h"

using namespace std;

int main(int argc, char** argv) {
        
    CController * c = new CController();

    c->showMenus();    
    c->startGame();
    
    delete c;
    return 0;
}

