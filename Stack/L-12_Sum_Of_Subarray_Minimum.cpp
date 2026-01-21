class Solution {
private:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n);
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && arr[i] <= arr[st.top()]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> prevSmallerEqualEle(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> pse(n);
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[i] < arr[st.top()]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int MOD = 1e9+7;
        vector<int> psee(n), nse(n);
        psee = prevSmallerEqualEle(arr);
        nse = nextSmallerEle(arr);
        for(int i = 0; i < n; i++) {
            int left = i - psee[i];
            int right = nse[i] - i;
            sum = (sum + (left*right*1LL*arr[i])%MOD)%MOD;
        }
        return sum;
    }
};

/**
        Given an array just find for an element howmany subarrays can we generate 
        which will have that element as minimum
*/