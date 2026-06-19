class Solution{
    public:

    void solve(int i,int j,int n,int m, string path, vector<vector<int>> &grid, vector<string> &ans)
    {
        if(i == n - 1 && j == m - 1)
        {
            ans.push_back(path);
            return;
        }

        if(i < 0 || j < 0 || i >= n || j >= m)
            return;

        if(grid[i][j] == 0)
            return;
        
        // Visit current
        grid[i][j] = 0;

        // Top
        solve(i-1,j,n,m,path+"U",grid,ans);

        // Right
        solve(i,j+1,n,m,path+"R",grid,ans);

        // Down
        solve(i+1,j,n,m,path+"D",grid,ans);

        //Left
        solve(i,j-1,n,m,path+"L",grid,ans);

        grid[i][j] = 1;
    }

    vector<string> findPath(vector<vector<int> > &grid) {
        //your code goes here
        vector<string> ans;
        int n = grid.size(),m = grid[0].size();

        if(grid[0][0] == 0 || grid[n-1][m-1] == 0)
            return ans;
        
        solve(0,0,n,m,"", grid,ans);

        return ans;
    }
};
