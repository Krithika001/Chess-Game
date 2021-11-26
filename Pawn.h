#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include"ChessPiece.h"
#endif // CHESSPIECE_H
class Pawn:public ChessPiece
{
    private:
        virtual char GetPiece()
        {
            return 'P';
        }
        bool legal_square(int SRow, int SCol, int DRow, int DCol, ChessPiece* qBoard[8][8]);
    public:
        Pawn(char col):ChessPiece(col){};
        ~Pawn(){};

};
