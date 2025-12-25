class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        set<pair<int, int>> st;
        vector<pair<int, int>> adj[V];
        vector<int> dist(V, 1e9);
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        st.insert({0, src});
        dist[src] = 0;
        while(!st.empty()) {
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);
            
            for(auto it: adj[node]) {
                int adjNode = it.first;
                int adjW = it.second;
                
                if(dis + adjW < dist[adjNode]) {
                    if(dist[adjNode] != 1e9)
                        st.erase({dist[adjNode], adjNode});
                        
                    dist[adjNode] = dis + adjW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        for(auto &it: dist) {
            if(it == 1e9) it = -1;
        }
        return dist;
    }
};