class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int element = st.top(); st.pop();
                int nse = i, pse = st.empty() ? -1 : st.top();
                ans = max(ans, (nse-pse-1)*heights[element]);
                
            }
            st.push(i);
        }
        while(!st.empty()) {
            int nse = n;
            int element = st.top(); st.pop();
            int pse = st.empty() ? -1 : st.top();
            ans = max(ans, heights[element]*(nse-pse-1));
        }
        return ans;
    }
};