class Solution {
  private:
    void toposort(int node, vector<int> adj[], 
    vector<int> &vis, stack<int> &st) {
        vis[node] = 1;
        for(auto it: adj[node]) {
            if(!vis[it]) {
                toposort(it, adj, vis, st);
            }
        }
        st.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        
        vector<int> vis(V, 0);
        stack<int> st;
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                toposort(i, adj, vis, st);
            }
        }
        
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};