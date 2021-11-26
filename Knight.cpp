#include "Knight.h"
char Knight::GetPiece()
{
	return 'N';
}
bool Knight::legal_square(int SRow,int SCol,int DRow,int DCol,ChessPiece* qBoard[8][8])
{
	// Destination square is unoccupied or occupied by opposite color
	if ((SCol==DCol+1)||(SCol==DCol-1))
    {
		if((SRow==DRow+2)||(SRow==DRow-2))
		{
			return true;
		}
    }
	if((SCol==DCol+2)||(SCol==DCol-2))
	{
		if((SRow==DRow+1)||(SRow==DRow-1))
		{
			return true;
		}
    }
		return false;
}
