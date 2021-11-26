#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include"ChessPiece.h"
#endif // CHESSPIECE_H
class Bishop:public ChessPiece
{
    virtual char GetPiece();
    bool legal_square(int SRow,int SCol,int DRow,int DCol,ChessPiece* qBoard[8][8]);
    public:
        Bishop(char col) : ChessPiece(col) {}
        ~Bishop() {}

};
