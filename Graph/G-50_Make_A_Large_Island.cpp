class DisjointSet {
public:
    vector<int> rank, parent, size;
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
    bool isValid(int adjrow, int adjcol, int row, int col) {
        return adjrow >= 0 && adjrow < row && adjcol >= 0 && adjcol < col;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DisjointSet ds(n*m);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    int dr[] = {1,0,-1,0};
                    int dc[] = {0,1,0,-1};

                    for(int k = 0; k < 4; k++) {
                        int adjrow = i + dr[k];
                        int adjcol = j + dc[k];
                        if(isValid(adjrow, adjcol, n, m) && grid[adjrow][adjcol] == 1) {
                            int nodeNo = i*m + j;
                            int adjNodeNo = adjrow*m + adjcol;
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
        }

        int ans = 0;
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if(grid[row][col] == 0) {
                    int dr[] = {1,0,-1,0};
                    int dc[] = {0,1,0,-1};
                    set<int> s;

                    for(int i = 0; i < 4; i++) {
                        int adjrow = row + dr[i];
                        int adjcol = col + dc[i];
                        if(isValid(adjrow, adjcol, n, m) && grid[adjrow][adjcol] == 1) {
                            int nodeNo = row*m + col;
                            int adjNodeNo = adjrow*m + adjcol;
                            s.insert(ds.findUPar(adjNodeNo));
                        }
                    }
                    int maxi = 1;
                    for(auto it: s) {
                        maxi += ds.size[it];
                    }

                    ans = max(ans, maxi);
                }
            }
        }
        for(int cellNo = 0; cellNo < n*m; cellNo++) {
            ans = max(ans, ds.size[ds.findUPar(cellNo)]);
        }
        return ans;
    }
};
