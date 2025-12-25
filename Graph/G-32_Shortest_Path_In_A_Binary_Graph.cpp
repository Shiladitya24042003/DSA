class Solution {
private:
    bool isValid(int nrow, int ncol, int n, int m, vector<vector<int>>& grid) {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int n = grid.size();
        int m = grid[0].size();
        set<pair<int, pair<int, int>>> st;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        st.insert({1, {0, 0}});
        dist[0][0] = 1;
        while(!st.empty()) {
            auto it = *(st.begin());
            int row = it.second.first;
            int col = it.second.second;
            int dis = it.first;
            st.erase(it);

            int dr[] = {-1,-1,-1, 0, 0, 1, 1, 1};
            int dc[] = {-1, 0, 1,-1, 1,-1, 0, 1};
            for(int i = 0; i < 8; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if(isValid(nrow, ncol, n, m, grid)) {
                    if(dis + 1 < dist[nrow][ncol]) {
                        if(dist[nrow][ncol] != 1e9)
                            st.erase({dist[nrow][ncol], {nrow, ncol}});
                        
                        dist[nrow][ncol] = dis + 1;
                        st.insert({dis + 1, {nrow, ncol}});
                    }
                }
            }
        }
        if(dist[n-1][m-1] == 1e9) return -1;
        return dist[n-1][m-1];
    }
};