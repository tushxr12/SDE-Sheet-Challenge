class Solution{
private:
    void bfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &grid)
    {
        visited[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for(int delRow = -1; delRow <= 1;delRow++)
            {
                for(int delCol = -1; delCol <= 1; delCol++)
                {
                    int nr = row + delRow;
                    int nc = col + delCol;

                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1' && !visited[nr][nc])
                    {
                        visited[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>> &grid){ 
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> visited(rows, vector<int>(cols,0));

        int ans = 0;
        for(int i = 0;i < rows;i++){
            for(int j = 0;j < cols;j++)
            {
                if(!visited[i][j] && grid[i][j] == '1')
                {
                    ans++;
                    bfs(i, j, visited, grid);
                }
            }
        }
        return ans;
    }
};
