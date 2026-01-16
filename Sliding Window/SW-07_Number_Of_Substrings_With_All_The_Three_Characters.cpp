class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        map<int, int> mpp;
        mpp[0] = mpp[1] = mpp[2] = -1;
        for(int i = 0; i < n; i++) {
            mpp[s[i]-'a'] = i;
            if(mpp[0] != -1 && mpp[1] != -1 && mpp[2] != -1) {
                cnt += 1 + min(mpp[0],min(mpp[1], mpp[2]));
            }
        }
        return cnt;
    }
};

/**
    We are just finding the smallest substring with all the characters a, b, c occuring atleast once and 
    we are expanding it backward to calculate all the possible substringa which include the smallest found substring
*/