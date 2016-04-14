#include "CIntelligence.h"
#include "DIFFICULTY.h"

CIntelligence::CIntelligence(){
}

CIntelligence::CIntelligence(DIFFICULTY d) : difficulty(d) {
    
}

void CIntelligence::changeDifficulty(DIFFICULTY d) {
    difficulty = d;
}

CIntelligence::~CIntelligence(){}

void CIntelligence::think() const{   
    
    // TODO   
    
}