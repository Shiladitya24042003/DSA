class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        int ans = -1;
        int l = 0, r = 0;
        map<char, int> mpp;
        while(r < n) {
            mpp[s[r]]++;
            if(mpp.size() <= k) {
                ans= max(ans, r-l+1);
            }
            else if(mpp.size() > k) {
                mpp[s[l]]--;
                if(mpp[s[l]] == 0) mpp.erase(s[l]);
                l++;
            }
            r++;
        }
        return ans;
    }
};