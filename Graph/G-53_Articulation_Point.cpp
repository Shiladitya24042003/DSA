#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int tin = 1;
    void dfs(int node, int parent, vector<int> &vis, vector<int> &time, vector<int> &low, vector<int> adj[], vector<int> &mark) {
        vis[node] = 1;
        time[node] = tin;
        low[node] = tin;
        tin++;
        int child = 0;

        for(auto it: adj[node]) {
            if(it == parent) continue;
            if(!vis[it]) {
                dfs(it, node, vis, time, low, adj, mark);
                low[node] = min(low[node], low[it]);
                if(low[it] >= time[node] && parent != -1) {
                    mark[it] = 1;
                }
                child++;
            }
            else {
                low[node] = min(low[node], low[it]);
            }
        }
        if(child > 1 && parent == -1) {
            mark[node] = 1;
        }
    }
public:
    vector<int> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it: connections) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        vector<int> mark;
        vector<int> time(n);
        vector<int> low(n);

        dfs(0, -1, vis, time, low, adj, mark);

        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(mark[i] == 1) {
                res.push_back(i);
            }
        }
        return res;
    }
};