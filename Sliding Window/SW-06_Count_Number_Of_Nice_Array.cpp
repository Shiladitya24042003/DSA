class Solution {
private:
    int numberofSubarraysWithLessThanEqualTok(vector<int> &nums, int k ) {
        int n = nums.size();
        int l = 0, r = 0;
        int cntodd = 0, cnt = 0;
        while(r < n) {
            if(nums[r] % 2) cntodd++;
            while(cntodd > k) {
                if(nums[l] % 2) cntodd--;
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return numberofSubarraysWithLessThanEqualTok(nums, k) - numberofSubarraysWithLessThanEqualTok(nums, k-1);
    }
};