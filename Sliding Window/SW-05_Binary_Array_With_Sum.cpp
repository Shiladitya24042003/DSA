class Solution {
private:
    int numSubarraysWithSumLesserThanEqualToGoal(vector<int> &nums, int goal) {
        if (goal < 0) return 0;
        int n = nums.size();
        int l = 0, r = 0;
        int sum = 0, cnt = 0;
        while(r < n) {
            sum += nums[r];
            while(l < n && sum > goal) {
                sum -= nums[l];
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSubarraysWithSumLesserThanEqualToGoal(nums, goal) - numSubarraysWithSumLesserThanEqualToGoal(nums, goal-1);
    }
};