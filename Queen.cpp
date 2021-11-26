#include "Queen.h"
char Queen::GetPiece()
{
    return 'Q';
}
bool Queen::legal_square(int SRow,int SCol,int DRow,int DCol,ChessPiece* qBoard[8][8])
{
    if(SRow==DRow)
    {
		// Make sure that all invervening squares are empty
		int coloffset=(DCol-SCol>0)?1:-1;
        for(int checkcol=SCol+coloffset;checkcol!=DCol;checkcol=checkcol+coloffset)
        {
			if(qBoard[SRow][checkcol]!=0)
			{
				return false;
			}
        }
		return true;
    }
    else if(DCol==SCol)
    {
		// Make sure that all invervening squares are empty
		int rowoffset=(DRow-SRow>0)?1:-1;
        for(int checkrow=SRow+rowoffset;checkrow!=DRow;checkrow=checkrow+rowoffset)
        {
			if(qBoard[checkrow][SCol]!=0)
			{
				return false;
			}
        }
		return true;
    }
    else if((DCol-SCol==DRow- SRow)||(DCol-SCol==SRow-DRow))
    {
		// Make sure that all invervening squares are empty
		int RowOffset=(DRow-SRow>0)?1:-1;
		int ColOffset=(DCol-SCol>0)?1:-1;
		int CheckRow;
		int CheckCol;
        for (CheckRow=SRow+RowOffset,CheckCol=SCol+ColOffset;CheckRow!=DRow;CheckRow=CheckRow+RowOffset,CheckCol=CheckCol+ColOffset)
		{
			if(qBoard[CheckRow][CheckCol]!= 0)
			{
				return false;
			}
        }
		return true;
    }
	return false;
}
