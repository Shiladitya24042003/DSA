#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int tin = 1;
    void dfs(int node, int parent, vector<int> &vis, vector<int> &time, vector<int> &low, vector<int> adj[], vector<vector<int>> &edges) {
        vis[node] = 1;
        time[node] = tin;
        low[node] = tin;
        tin++;

        for(auto it: adj[node]) {
            if(it == parent) continue;
            if(!vis[it]) {
                dfs(it, node, vis, time, low, adj, edges);
                low[node] = min(low[node], low[it]);
                if(low[it] > time[node]) {
                    edges.push_back({node, it});
                }
            }
            else {
                low[node] = min(low[node], low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it: connections) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n);
        vector<vector<int>> edges;
        vector<int> time(n);
        vector<int> low(n);

        dfs(0, -1, vis, time, low, adj, edges);

        return edges;
    }
};