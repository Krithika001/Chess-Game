#include"Pawn.h"
#include"Knight.h"
#include"Bishop.h"
#include"Rook.h"
#include"Queen.h"
#include"King.h"
class Board
{

    public:
        Board();
        ~Board();
        void print();
        bool check(char col);
        bool Move(char col);
        ChessPiece* mBoard[8][8];
};
