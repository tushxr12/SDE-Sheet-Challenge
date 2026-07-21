class Solution{
private:
    bool bfs(int node, vector<int> adj[], int color[])
    {
        queue<int> q;
        q.push(node);
        color[node] = 0;

        while(!q.empty())
        {
            auto topNode = q.front();
            q.pop();

            for(auto &ngbr : adj[topNode])
            {
                if(color[ngbr] == -1)
                {
                    color[ngbr] = !color[topNode];
                    q.push(ngbr);
                }
                else if(color[ngbr] == color[topNode])
                    return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(int V, vector<vector<int>> edges)  {
        int color[V];
        for(int i = 0;i < V;i++)
            color[i] = -1;
        
        vector<int> adj[V];
        for(auto i : edges)
        {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i = 0;i < V;i++)
        {
            if(color[i] == -1)
            {
                if(!bfs(i, adj, color))
                    return false;
            }
        }
        return true;
    }
};
