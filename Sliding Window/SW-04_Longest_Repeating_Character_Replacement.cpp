class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, r = 0;
        int maxfreq = 0, maxlen = 0;
        map<char, int> mpp;
        while(r < n) {
            mpp[s[r]]++;
            maxfreq = max(maxfreq, mpp[s[r]]);
            int change = r-l+1 - maxfreq;
            if(change > k) {
                mpp[s[l]]--;
                if(mpp[s[l]] == 0) mpp.erase(s[l]);
                l++;
            }
            else maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};