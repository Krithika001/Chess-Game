#include "Board.h"
#include<iostream>
using namespace std;
Board::Board()
{
    for(int Row=0;Row<8;++Row)
    {
		for(int Col=0;Col<8;++Col)
		{
			mBoard[Row][Col]=0;
        }
    }
	// Allocate and place black pieces
	for (int Col=0;Col<8;++Col)
	{
		mBoard[6][Col]=new Pawn('B');
    }
	mBoard[7][0]=new Rook('B');
    mBoard[7][1]=new Knight('B');
	mBoard[7][2]=new Bishop('B');
    mBoard[7][3]=new King('B');
	mBoard[7][4]=new Queen('B');
    mBoard[7][5]=new Bishop('B');
	mBoard[7][6]=new Knight('B');
    mBoard[7][7]=new Rook('B');
    // Allocate and place white pieces
	for(int Col=0;Col<8;++Col)
	{
		mBoard[1][Col]=new Pawn('W');
    }
	mBoard[0][0]=new Rook('W');
    mBoard[0][1]=new Knight('W');
	mBoard[0][2]=new Bishop('W');
    mBoard[0][3]=new King('W');
	mBoard[0][4]=new Queen('W');
	mBoard[0][5]=new Bishop('W');
	mBoard[0][6]=new Knight('W');
	mBoard[0][7]=new Rook('W');
}

Board::~Board()
{
   for(int Row=0;Row<8;++Row)
   {
        for(int Col=0;Col<8;++Col)
        {
			delete mBoard[Row][Col];
            mBoard[Row][Col]=0;
        }
    }
}
void Board::print()
{
    const int squareWidth = 4;
    const int squareHeight = 3;
    for(int Row=0;Row<8*squareHeight;++Row)
    {
		int squareRow=Row/squareHeight;
        // Print side border with numbering
		if(Row%3==1)
		{
			cout<<'*'<<(char)('1'+7-squareRow)<<'*';
		}
        else
        {
			cout << "***";
        }
		// Print the chess board
		for(int Col=0;Col<8*squareWidth;++Col)
		{
			int squareCol=Col/squareWidth;
            if(((Row%3)==1)&&((Col%4)==1||(Col%4)==2) && mBoard[7-squareRow][squareCol]!=0)
            {
				if((Col%4)==1)
				{
                    cout<<mBoard[7-squareRow][squareCol]->Getcolour();
				}
                else
                {
					cout<<mBoard[7-squareRow][squareCol]->GetPiece();
                }
            }
            else
            {
				if((squareRow+squareCol)%2==1)
				{
                    cout << '-';
				}
                else
                {
					cout<<' ';
                }
            }
        }
		cout << endl;
    }
		// Print the bottom border with numbers
	for (int Row=0;Row<squareHeight;++Row)
    {
        if(Row%3==1)
        {
			cout<<"***";
            for(int Col=0;Col<8*squareWidth;++Col)
            {
				int squareCol=Col/squareWidth;
                if((Col%4)==1)
                {
					cout<<(squareCol+1);
                }
                else
                {
					cout << '*';
				}
            }
			cout << endl;
        }
        else
        {
			for(int Col=1;Col<9*squareWidth;++Col)
			{
					cout<<'*';
            }
			cout << endl;
        }
    }
}
bool Board::check(char col)
{
    // Find the king
    int KingRow;
    int KingCol;
    for(int Row=0;Row<8;++Row)
    {
		for(int Col=0;Col<8;++Col)
		{
			if(mBoard[Row][Col]!=0)
			{
				if(mBoard[Row][Col]->Getcolour()==col)
				{
					if(mBoard[Row][Col]->GetPiece()=='K')
					{
						KingRow=Row;
                        KingCol=Col;
                    }
                }
            }
        }
    }
	// Run through the opponent's pieces and see if any can take the king
	for(int Row=0;Row<8;++Row)
	{
		for(int Col=0;Col<8;++Col)
		{
			if(mBoard[Row][Col]!=0)
			{
				if(mBoard[Row][Col]->Getcolour()!=col)
				{
					if(mBoard[Row][Col]->legal_move(Row,Col,KingRow,KingCol,mBoard))
					{
						return true;
					}
                }
            }
        }
    }
	return false;
}
bool Board::Move(char col)
{
    // Run through all pieces
	for(int Row=0;Row<8;++Row)
    {
		for(int Col=0;Col<8;++Col)
		{
			if(mBoard[Row][Col]!=0)
			{
				// If it is a piece of the current player, see if it has a legal move
				if(mBoard[Row][Col]->Getcolour()==col)
				{
					for(int moveRow=0;moveRow<8;++moveRow)
					{
						for(int moveCol=0;moveCol<8;++moveCol)
						{
							if(mBoard[Row][Col]->legal_move(Row,Col,moveRow,moveCol,mBoard))
							{
								// Make move and check whether king is in check
								ChessPiece*temp=mBoard[moveRow][moveCol];
                                mBoard[moveRow][moveCol]=mBoard[Row][Col];
                                mBoard[Row][Col]=0;
								bool canMove=!(check(col));
								// Undo the move
								mBoard[Row][Col]=mBoard[moveRow][moveCol];
								mBoard[moveRow][moveCol]=temp;
								if(canMove)
								{
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
	return false;
}
