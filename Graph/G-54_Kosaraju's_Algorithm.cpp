#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st) {
        vis[node] = 1;
        for(auto it: adj[node]) {
            if(!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }

    public:
    int kosaraju(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto it: edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
        }

        stack<int> st;
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }

        vector<int> revAdj[n];
        for(auto it: edges) {
            int u = it[0], v = it[1];
            revAdj[v].push_back(u);
        }
        fill(vis.begin(), vis.end(), 0);
        int scc = 0;
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            if(!vis[node]) {
                scc++;
                dfs(node, vis, revAdj, st);
            }
        }
        return scc;
    }
};