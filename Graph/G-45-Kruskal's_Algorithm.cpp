#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if(node == parent[node]) {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int spanningTree(int n, vector<vector<int>> adj[]) {
        vector<pair<int, pair<int, int>>> edges;
        for(int i = 0; i < n; i++) {
            for(auto it: adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({wt, {node, adjNode}});
            }
        }

        DisjointSet ds(n);
        sort(edges.begin(), edges.end());

        int mst = 0;
        for(auto it: edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if(ds.findUPar(u) != ds.findUPar(v)) {
                mst += wt;
                ds.unionBySize(u, v);
            }
        }
        return mst;
    }
};
int main() {
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    if(ds.findUPar(3) == ds.findUPar(7)) {
        cout<<"Same\n";
    }
    else cout<<"Not Same\n";
    ds.unionBySize(3, 7);
    if(ds.findUPar(3) == ds.findUPar(7)) {
        cout<<"Same\n";
    }
    else cout<<"Not Same\n";
}