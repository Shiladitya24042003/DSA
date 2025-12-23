class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        queue<pair<int, int>> q;
        vector<int> dist(V, INT_MAX);
        vector<int> adj[V];
        for(auto it: edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        q.push({src, 0});
        dist[src] = 0;
        while(!q.empty()) {
            auto it = q.front();
            int node = it.first;
            int dis = it.second;
            q.pop();
            
            for(auto adjNode: adj[node]) {
                if(dist[adjNode] > dis+1) {
                    dist[adjNode] = dis+1;
                    q.push({adjNode, dis+1});
                }
            }
        }
        for(auto &it: dist) {
            if(it == INT_MAX) it = -1;
        }
        return dist;
    }
};
