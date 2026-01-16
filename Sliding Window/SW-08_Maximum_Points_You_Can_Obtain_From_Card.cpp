class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int l = 0, r = 0;
        int totalSum = 0;
        for(auto it: cardPoints) totalSum += it;
        int minsum = 1e9;
        int sum = 0;
        while(r < n) {
            sum += cardPoints[r];
            if(r-l+1 > n-k) {
                sum -= cardPoints[l];
                l++;
            }
            if(r-l+1 == n-k) minsum = min(minsum, sum);
            r++;
        }
        if(minsum == 1e9) minsum = 0;
        return totalSum - minsum;
    }
};