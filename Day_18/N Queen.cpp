class Solution {
public:
    bool isSafe(vector<string> &board, int row, int col)
    {
        int r = row, c = col;

        // Upper diagonal
        while(r >= 0 && c >= 0)
        {
            if(board[r--][c--] == 'Q')
                return false;
        }

        r = row, c = col;

        // Top
        while(r >= 0)
        {
            if(board[r--][c] == 'Q')   
                return false;
        }

        r = row;

        // Top Right diagonal
        while(r >= 0 && c < board[0].size())
        {
            if(board[r--][c++] == 'Q')
                return false;
        }

        return true;
    }

    void func(int index, vector<vector<string>> &ans, vector<string> &board)
    {
        if(index == board.size())
        {
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < board[0].size();col++)
        {
            if(isSafe(board, index, col))
            {
                board[index][col] = 'Q';
                func(index + 1,ans,board);
                board[index][col] = '.';
            }
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        //your code goes here
        vector<vector<string>> ans;
        vector<string> board(n, string(n,'.'));

        func(0, ans, board);
        return ans;
    }
};
