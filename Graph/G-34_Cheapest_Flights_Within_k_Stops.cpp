class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        vector<int> dist(n, 1e9);
        for(auto it: flights) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
        }
        set<pair<int, pair<int, int>>> st;
        st.insert({0, {src, 0}});
        dist[src] = 0;

        while(!st.empty()) {
            auto it = *(st.begin());
            int stop = it.first;
            int node = it.second.first;
            int dis = it.second.second;
            st.erase(it);

            if(stop > k) continue;
            for(auto it: adj[node]) {
                int adjNode = it.first;
                int wt = it.second;

                if(dis + wt < dist[adjNode]) {
                    dist[adjNode] = dis + wt;
                    
                    st.insert({stop+1, {adjNode, dist[adjNode]}});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
