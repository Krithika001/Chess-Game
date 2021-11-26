#include "ChessPiece.h"
#include<iostream>
bool ChessPiece::legal_move(int SRow, int SCol, int DRow, int DCol, ChessPiece* qBoard[8][8])
{
    ChessPiece* d=qBoard[DRow][DCol];
    if(d==0||colour!=d->Getcolour())
    {
        return legal_square(SRow,SCol,DRow,DCol,qBoard);
    }
    return false;
}
char ChessPiece::Getcolour()
{
    return colour;
}
