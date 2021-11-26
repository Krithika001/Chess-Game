class ChessPiece
{
   char colour;
   virtual bool legal_square(int SRow, int SCol, int DRow, int DCol, ChessPiece* qBoard[8][8])=0;
   public:
       ChessPiece(char col) : colour(col){}
       ~ChessPiece(){}
       virtual char GetPiece() = 0;
       char Getcolour();
       bool legal_move(int SRow, int SCol, int DRow, int DCol, ChessPiece* qBoard[8][8]);
};

