class Solution{
private:
    void dfs(int node, vector<int> adj[], vector<int> &visited, stack<int> &st)
    {
        visited[node] = 1;
        for(auto it : adj[node])
        {
            if(!visited[it])
            {
                dfs(it, adj, visited, st);
            }
        }
        st.push(node);
    }
public:
    vector<int> topoSort(int V, vector<int> adj[]){
        vector<int> visited(V,0);
        stack<int> st;

        for(int i = 0;i < V;i++)
        {
            if(!visited[i])
            {
                dfs(i, adj, visited, st);
            }
        }

        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
