// User function Template for C++
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
    bool valid(int adjrow, int adjcol, int n, int m) {
        if(adjrow >= 0 && adjrow < n && adjcol >= 0 && adjcol < m) return true;
        return false;
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> ans;
        int cnt = 0;
        for(auto it: operators) {
            int row = it[0];
            int col = it[1];
            if(vis[row][col] == 1) {
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;
            int dr[] = {1,0,-1,0};
            int dc[] = {0,1,0,-1};
            for(int i = 0; i < 4; i++) {
                int adjrow = row + dr[i];
                int adjcol = col + dc[i];
                if(valid(adjrow, adjcol, n, m)) {
                    if(vis[adjrow][adjcol] == 1) {
                        int nodeNo = row*m + col;
                        int adjnodeNo = adjrow*m+adjcol;
                        if(ds.findUPar(nodeNo) != ds.findUPar(adjnodeNo)) {
                            cnt--;
                            ds.unionBySize(nodeNo, adjnodeNo);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
