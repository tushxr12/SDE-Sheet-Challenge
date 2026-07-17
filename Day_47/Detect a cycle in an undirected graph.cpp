class Solution{
private:
    bool detect(int src, vector<int> adj[], vector<bool> &visited, int prev)
    {
        visited[src] = 1;
        queue<pair<int,int>> q;
        q.push({src, -1});

        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto &ngbr : adj[node])
            {
                if(!visited[ngbr])
                {
                    visited[ngbr] = 1;
                    q.push({ngbr, node});
                }
                else if(parent != ngbr)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(int src, vector<int> adj[], vector<bool> &visited, int prev)
    {
        visited[src] = 1;

        for(auto &ngbr : adj[src])
        {
            if(!visited[ngbr])
            {
                if(dfs(ngbr, adj, visited, src))
                    return true;
            }
            else if(ngbr != prev)
            {
                return true;
            }
        }
        
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        bool ans = false;

        for(int i = 0;i < V;i++)
        {
            if(!visited[i])
            {
                if(dfs(i, adj, visited,-1))
                    return true;
            }
        }
        return false;
    }
};
