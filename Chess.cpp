#include "Chess.h"
#include<iostream>
using namespace std;
void Chess::start()
{
    do
    {
        next_move(board.mBoard);
		alter_turn();
	} while (!check_mate());
		board.print();
}
void Chess::next_move(ChessPiece* qBoard[8][8])
{
    bool valid_move	= false;
    do
    {
		board.print();
		// Get input and convert to coordinates
		cout<<turn<<"'s Move: ";
        int start_move;
        cin>>start_move;
        int startRow=(start_move/10)-1;
        int startCol=(start_move%10)-1;
		cout << "To: ";
		int end_move;
        cin>>end_move;
		int endRow=(end_move/10)-1;
        int endCol=(end_move%10)-1;
		// Check that the indices are in range
		// and that the source and destination are different
		if((startRow>=0&&startRow<=7)&&(startCol>=0&&startCol<=7)&&(endRow>=0&&endRow<=7)&&(endCol>=0&&endCol<=7))
		{
			// Additional checks in here
			ChessPiece* currPiece=qBoard[startRow][startCol];
            // Check that the piece is the correct color
			if((currPiece!=0)&&(currPiece->Getcolour()==turn))
			{
				// Check that the destination is a valid destination
				if(currPiece->legal_move(startRow,startCol,endRow,endCol,qBoard))
				{
					// Make the move
					ChessPiece* temp=qBoard[endRow][endCol];
                    qBoard[endRow][endCol]=qBoard[startRow][startCol];
                    qBoard[startRow][startCol]=0;
                    // Make sure that the current player is not in check
					if(!board.check(turn))
					{
						delete temp;
                        valid_move=true;
                    }
                    else
                    {
                        // Undo the last move
                        qBoard[startRow][startCol]=qBoard[endRow][endCol];
							qBoard[endRow][endCol]=temp;
                    }
                }
            }
        }
		if(!valid_move)
        {
            cout << "Invalid Move!" << endl;
		}
    } while(!valid_move);
}
void Chess::alter_turn()
{
    turn=(turn=='W')?'B':'W';
}
bool Chess::check_mate()
{
    // Check that the current player can move
    // If not, we have a stalemate or checkmate
	bool can_move(false);
	can_move=board.Move(turn);
	if(!can_move)
    {
		if(board.check(turn))
		{
			alter_turn();
            cout<<"Checkmate, "<<turn<<" Wins!"<<endl;
        }
        else
        {
			cout<<"Stalemate!"<<endl;
        }
    }
	return !can_move;
}
