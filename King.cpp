#include "King.h"
char King::GetPiece()
{
    return 'K';
}
bool King::legal_square(int SRow,int SCol,int DRow,int DCol,ChessPiece* qBoard[8][8])
{
    int row=DRow-SRow;
    int col=DCol-SCol;
	if(((row>=-1)&&(row<=1))&&((col>=-1)&&(col<=1)))
    {
        return true;
	}
    return false;
}
