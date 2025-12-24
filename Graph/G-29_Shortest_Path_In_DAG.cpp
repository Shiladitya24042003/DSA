// User function Template for C++
class Solution {
  private:
    void toposort(int node, vector<int> &vis, 
    vector<pair<int, int>> adj[], stack<int> &st) {
        vis[node] = 1;
        for(auto it: adj[node]) {
            if(!vis[it.first]) {
                toposort(it.first, vis, adj, st);
            }
        }
        st.push(node);
    }  
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[V];
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
        }
        vector<int> vis(V,0);
        stack<int> st;
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                toposort(i, vis, adj, st);
            }
        }
        
        vector<int> dist(V, 1e9);
        dist[0] = 0;
        
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            
            for(auto it: adj[node]) {
                if(dist[node] + it.second < dist[it.first]) {
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
        for(auto &it: dist) {
            if(it == 1e9) it = -1;
        }
        return dist;
    }
};
