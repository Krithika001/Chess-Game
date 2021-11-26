#include "Pawn.h"
#include<iostream>
using namespace std;
bool Pawn::legal_square(int SRow,int SCol,int DRow, int DCol,ChessPiece* qBoard[8][8])
{
    ChessPiece* qp = qBoard[DRow][DCol];
    if (qp==0)
    {
        // Destination square is unoccupied
		if (SCol==DCol)
		{
			if (Getcolour()=='W')
			{
				if (DRow==SRow+1)
				{
					return true;
				}
            }
            else
            {
				if (DRow==SRow-1)
				{
					return true;
				}
            }
        }
    }
    else
    {
        // Dest holds piece of opposite color
		if ((SCol==DCol+1)||(SCol==DCol-1))
		{
			if (Getcolour()=='W')
			{
				if (DRow==SRow+1)
				{
					return true;
				}
            }
            else
            {
				if (DRow==SRow-1)
				{
					return true;
				}
            }
        }
    }
	return false;
}
