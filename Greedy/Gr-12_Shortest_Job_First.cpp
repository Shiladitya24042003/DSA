// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        int n = bt.size();
        sort(bt.begin(), bt.end());
        int waitTime = 0, t = 0;
        for(int i = 0; i < n; i++) {
            waitTime += t;
            t += bt[i];
        }
        return waitTime/n;
    }
};