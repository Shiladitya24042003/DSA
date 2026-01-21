class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n);
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && arr[i] <= st.top()) {
                st.pop();
            }
            nse[i] = st.empty() ? -1 : st.top();
            st.push(arr[i]);
        }
        return nse;
    }
};