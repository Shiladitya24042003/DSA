class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maximumIndxReached = 0;
        for(int i = 0; i < n; i++) {
            int newIndx = nums[i]+i;
            if(maximumIndxReached < i) return false;
            maximumIndxReached = max(maximumIndxReached, nums[i]+i);
        }
        return maximumIndxReached >= n-1;
    }
};