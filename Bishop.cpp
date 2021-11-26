#include "Bishop.h"
char Bishop::GetPiece()
{
	return 'B';
}
bool Bishop::legal_square(int SRow,int SCol,int DRow,int DCol,ChessPiece* qBoard[8][8])
{
	if((DCol-SCol==DRow-SRow)||(DCol-SCol==SRow-DRow))
    {
		// Make sure that all invervening squares are empty
		int rowoffset=(DRow-SRow>0)?1:-1;
		int coloffset=(DCol-SCol>0)?1:-1;
		int checkrow;
		int checkcol;
		for (checkrow=SRow+rowoffset,checkcol=SCol+coloffset;checkrow!=DRow;checkrow=checkrow+rowoffset,checkcol=checkcol+coloffset)
		{
			if(qBoard[checkrow][checkcol]!=0)
			{
				return false;
			}
		}
		return true;
	}
	return false;
}
