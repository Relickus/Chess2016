#include "CIntelligence.h"
#include "DIFFICULTY.h"
#include "CPiece.h"
#include "CCommand.h"
#include "CPawn.h"
#include "CGameSession.h"

CIntelligence::CIntelligence(){
}

CIntelligence::CIntelligence(int d) : difficulty(d) {
    
}

void CIntelligence::changeDifficulty(int d) {
    difficulty = d;
}

CIntelligence::~CIntelligence(){}

void CIntelligence::think() const{   
    
    // TODO   Minimax
    
}

void CIntelligence::eraseCheckMoves(MoveList & l, CGameSession & gS) const{
        
    MoveList tmplist;
    
    for(size_t i = 0; i < l.size();++i){
        MyMove m = l.getMove(i);
        
        if( ! gS.gameBoard.tryMove(m,gS)){
        }
        else{
            tmplist.add(m,m.figure);
        }        
//        gS.gameBoard.undoMove(move, gS);   
    }

    l.clear();
    l.concat(tmplist);    
}   


MyMove CIntelligence::getMove(CGameSession & gS){
    
    allMoves.clear();
    MoveList l;
    
    findAllFigures(gS.gameBoard);    
    
    for(size_t i = 0; i < figuresVec.size(); ++i){        
          l = figuresVec.at(i)->getLegalMoves(gS); 
        
        allMoves.concat(l); 
    }
         
    eraseCheckMoves(allMoves,gS);
    
    allMoves.print();

    if(allMoves.isEmpty()){
        return MyMove(-1,-1,-1,-1);
    }    
    
    // minimax vyhodi nejakej move a vrati ho...
    
    int bestIdx = getBestIdx(allMoves,gS.gameBoard);
    
    return allMoves.getMove(bestIdx);    
}

CCommand CIntelligence::getCommand(CGameSession & gS) {
    
    MyMove m = getMove(gS);
    if(m.isFicture()){
        return CCommand(SURRENDER);
    }
    
    return CCommand(m);
}

int CIntelligence::getBestIdx(MoveList& list,CBoard & board) const {

    if(difficulty == 0){
        srand(time(NULL));
        return rand() % (allMoves.size());
    }
    
    int bestValPcs = 0;
    int bestValSlot = 0;
    int bestIdxPcs = -1;
    int bestIdxSlot = -1;
    int bestIdxTotal = 0;
    int bestValueTotal = 0;
    
    
    for (int i = 0; i < list.size(); i++) {
        CPiece * pcs = list.getMove(i).figure;
        if(pcs == NULL)
            continue;
        int v = (pcs->getValue())*10; // !!!!!!!!!!!!!!! TODO VYRAZENA FIGURA
        
        if(v > bestValPcs){
            bestValPcs = v;
            bestIdxPcs = i;
        }
    }
    
    for (int i = 0; i < list.size(); i++) {
        
        MyMove tmp = list.getMove(i);
        int v = board.getSlotValue(tmp.toX,tmp.toY);
        if(v > bestValSlot){
            bestValSlot = v;
            bestIdxSlot = i;
        }
        if(list.getMove(i).figure == NULL)
            continue;
        else{
            
            if(list.getMove(i).figure->getValue()*10 + v > bestValueTotal){
                bestValueTotal = list.getMove(i).figure->getValue()*10 + v;
                bestIdxTotal = i;
            }
        }
    }
    
    if(difficulty == 1)
        return bestIdxPcs > bestIdxSlot ? bestIdxPcs : bestIdxSlot;
    
    else
        return bestIdxTotal;    
}
