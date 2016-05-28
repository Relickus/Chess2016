#include "MyMove.h"


MyMove::MyMove() : takenFigure(NULL) {

}

MyMove::MyMove(int X, int Y, CPiece* takenfigure) : x(X),y(Y), takenFigure(takenfigure){

}

MyMove::~MyMove() {

}
