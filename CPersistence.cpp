#include "CPersistence.h"

CPersistence::CPersistence(CGameSession* b) {
    gamePtr = b;    
}

CPersistence::CPersistence() {
    gamePtr = NULL;
}

CPersistence::~CPersistence(){
}