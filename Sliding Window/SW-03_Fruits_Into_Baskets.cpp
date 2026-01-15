class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int res = INT_MIN, i = 0;
        map<int, int> mpp;
        for(int j = 0; j < n; j++) {
            mpp[fruits[j]]++;
            if(mpp.size() > 2) {
                mpp[fruits[i]]--;
                if(mpp[fruits[i]] == 0) mpp.erase(fruits[i]);
                i++;
            }
            
            res = max(res, j-i+1);
        }
        return res;
    }
};