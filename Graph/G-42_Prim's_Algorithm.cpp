#include<bits/stdc++.h>
using namespace std;

class Solution {
    int spanningTree(int n, vector<vector<int>> edges) {
        class Solution {
  public:
    int spanningTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj[n];
        for(auto &it : edges) {
            int u = it[0], v = it[1], wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<int> vis(n, 0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0, 0});
        int sum = 0;

        while(!pq.empty()) {
            auto it = pq.top(); pq.pop();

            int wt = it.first;
            int node = it.second;

            if(vis[node]) continue;

            vis[node] = 1;
            sum += wt;

            for(auto &edge : adj[node]) {
                int adjNode = edge[0];
                int adjWt = edge[1];
                pq.push({adjWt, adjNode});
            }
        }
        return sum;
    }
};

    }
};
