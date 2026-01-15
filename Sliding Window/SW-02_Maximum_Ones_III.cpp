class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int zero = 0;
        int l = 0, r = 0;
        int ans = 0;
        while(r < n) {
            if(nums[r] == 0) zero++;
            if(zero > k) {
                if(nums[l] == 0) zero--;
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};

/**
    Just change the question statement to this:
    longest subarray of nums with atmost k zeros
    
    And actually this justify too; because when we select a subarray we only can change k zeroes.
*/