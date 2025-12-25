class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        set<pair<int, pair<int, int>>> st;
        vector<vector<int>> efforts(n, vector<int>(m, 1e9));
        st.insert({0, {0, 0}});
        efforts[0][0] = 0;

        while(!st.empty()) {
            auto it = *(st.begin());
            int row = it.second.first;
            int col = it.second.second;
            int eff = it.first;
            st.erase(it);

            int dr[] = {1,0,-1,0};
            int dc[] = {0,1,0,-1};
            for(int i = 0; i < 4; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int adjEff = max(eff, abs(heights[row][col] - heights[nrow][ncol]));
                    if(adjEff < efforts[nrow][ncol]) {
                        if(efforts[nrow][ncol] != 1e9) 
                            st.erase({efforts[nrow][ncol], {nrow, ncol}});

                        efforts[nrow][ncol] = adjEff;
                        st.insert({efforts[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }
        return efforts[n-1][m-1];
    }
};