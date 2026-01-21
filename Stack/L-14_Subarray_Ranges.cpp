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
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;
        vector<int> psee(n), nse(n);
        psee = prevSmallerEqualEle(arr);
        nse = nextSmallerEle(arr);
        for(int i = 0; i < n; i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;
            sum = sum + (left*right*1LL*arr[i]);
        }
        return sum;
    }




     vector<int> nextLargerEle(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> nge(n);
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }
    vector<int> prevLargerEqualEle(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> pge(n);
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pge;
    }

    long long sumSubarrayMax(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;
        vector<int> pgee(n), nge(n);
        pgee = prevLargerEqualEle(arr);
        nge = nextLargerEle(arr);
        for(int i = 0; i < n; i++) {
            long long left = i - pgee[i];
            long long right = nge[i] - i;
            sum = sum + (left*right*1LL*arr[i]);
        }
        return sum;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        return (sumSubarrayMax(nums) - sumSubarrayMins(nums));
    }
};