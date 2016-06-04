#include "CSlot.h"
#include "CPiece.h"
#include  <iostream>


//
//CSlot::acceptVisitor(const CVisitor& v) const{
//    heldPiece.acceptVisitor(v);
//}

CSlot::CSlot() : heldPiece(NULL){

}
CSlot::~CSlot(){
    delete heldPiece;
}

CPiece * CSlot::getHeldPiece() const{
    return heldPiece;
}

void CSlot::setHeldPiece(CPiece* p){
    
    heldPiece = p;
}

void CSlot::setValue(int v) {
    value = v;
}

int CSlot::getValue() const {
    return value;
}
