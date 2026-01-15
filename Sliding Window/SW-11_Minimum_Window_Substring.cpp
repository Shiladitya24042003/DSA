class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int l = 0, r = 0;
        map<char, int> mpp;
        for(auto it: t) {
            mpp[it]++;
        }
        int indx = -1, len = 1e9;
        int cnt = 0;
        while(r < n) {
            if(mpp[s[r]] > 0) cnt++;
            mpp[s[r]]--;
            
            while(l < n && cnt == m) {
                if(r-l+1 < len) {
                    len = r-l+1;
                    indx = l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }
            r++;
        }
        string ans = "";
        if(indx == -1) return "";
        for(int i = indx; i < indx+len; i++) {
            ans += s[i];
        }
        return ans;
    }
};