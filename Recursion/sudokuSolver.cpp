    bool isSafe(int row, int col,vector<vector<char>>& board, char num )
    {
        //Check in full row
        for(int i=0; i<9; i++)
            if(board[i][col]==num)
                return false;
        
        //check in  full column
        for(int i=0; i<9; i++)
            if(board[row][i]==num)
                return false;
        
        //check in 3*3 matrix
        for(int i=0; i<9; i++)
        {
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==num)
                return false;
        }
        return true;
        
    }
    bool solve(vector<vector<char>>& board)
    {
        //Traverse inside matrix of 9*9
        for(int row=0; row<9; row++)
        {
            for(int col=0; col<9; col++)
            {
                //we have see emtpty cell
                if(board[row][col]=='.')
                {
                    //yaha pe 1 se 9 tak value daal ke dekh lo
                    for(int i='1'; i<='9'; i++)
                    {
                        //check kar lo is it safe to put that value one by obe
                        if(isSafe(row, col,board,i))
                        {
                            //agr safe hai waha pe rakhna then go and put the value and call recurision
                            board[row][col]=i;
                            //Next recursion call and check if it backtracks then place empty cell to it
                            if(solve(board))
                                return true;
                            else
                                board[row][col]='.';
                        }
                    }
                    //Iska matlb 1 se le ke 9 tak kisi me answer nai aaya
                    //in this case ans is not possible so return false
                    
                    return false;
                }
            }
        }
        //this means poora solve ho gya and reached end 
        return true;

    }
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board);
        
    }