class Solution {
private:
    int helper(vector<int> &nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        int cnt = 0;
        map<int, int> mpp;
        while(r < n) {
            mpp[nums[r]]++;
            while(l < n && mpp.size() > k) {
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
            cnt += r-l+1;;
            r++;
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k-1);
    }
};