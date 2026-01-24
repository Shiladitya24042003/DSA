class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int ans = 0;
        for(int i = 0; i <= n; i++) {
            while(!st.empty() && (i == n || heights[st.top()] > heights[i])) {
                int element = st.top(); st.pop();
                int nse = i, pse = st.empty() ? -1 : st.top();
                ans = max(ans, (nse-pse-1)*heights[element]);
                
            }
            st.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;

        vector<int> histogram(m, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '0') {
                    histogram[j] = 0;
                }
                else histogram[j] += 1;
            }

            ans = max(ans, largestRectangleArea(histogram));
        }
        return ans;
    }
};