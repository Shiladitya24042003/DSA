class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<tuple<int, int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j, 0});
                    vis[i][j] = 1;
                }
            }
        }
        int ans = 0;
        while(!q.empty()) {
            auto it = q.front();
            int row = get<0>(it);
            int col = get<1>(it);
            int time = get<2>(it);
            ans = max(ans, time);
            q.pop();

            int dr[] = {1,0,-1,0};
            int dc[] = {0,1,0,-1};
            for(int i = 0; i < 4; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 1 && grid[nrow][ncol] == 1) {
                    q.push({nrow, ncol, time+1});
                    vis[nrow][ncol] = 1;
                    grid[nrow][ncol] = 2;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) return -1;
            }
        }
        return ans;
    }
};