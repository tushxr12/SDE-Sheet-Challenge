class Solution {
  public:

    void dfs(int node, vector<vector<int>> &adj, int vis[], vector<int> &ans)
    {
        vis[node] = 1;
        ans.push_back(node);

        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                dfs(it, adj, vis, ans);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<vector<int>> edges) {
        int vis[V] ={0};
        vector<int> ans;

        vector<vector<int>> adj(V);
        for(auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for(int i = 0;i < V;i++){
            if(!vis[i])
            {
                dfs(i, adj, vis, ans);
            }
        }
        return ans;
    }
    
    void bfs(int node, vector<vector<int>> &adj, int vis[], vector<int> &ans)
    {
        queue<int> q;
        q.push(node);

        while(!q.empty())
        {
            auto node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto it : adj[node])
            {
                if(!vis[it])
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }


    vector<int> bfsOfGraph(int V, vector<vector<int>> edges) {
        int vis[V] ={0};
        vector<int> ans;

        vector<vector<int>> adj(V);
        for(auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for(int i = 0;i < V;i++){
            if(!vis[i])
            {
                vis[i] = 1;
                bfs(i, adj, vis, ans);
            }
        }
        return ans;
    }
};
