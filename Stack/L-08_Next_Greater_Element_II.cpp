class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i = 2*n-1; i >= 0; i--) {
            int indx = i%n;
            while(!st.empty() && st.top() <= nums[indx]) {
                st.pop();
            }
            if(st.empty() && i < n) {
                ans[i] = -1;
            }
            else {
                if(i < n) ans[i] = st.top();
            }
            st.push(nums[indx]);
        }
        return ans;
    }
};