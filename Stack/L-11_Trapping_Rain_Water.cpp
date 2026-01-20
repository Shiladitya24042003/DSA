class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int cnt = 0;
        int l = 0, r = n-1;
        int leftmax = 0, rightmax = 0;
        while(l < r) {
            if(height[l] <= height[r]) {
                if(height[l] >= leftmax) leftmax = height[l];
                else cnt += leftmax - height[l];
                l++;
            }
            else {
                if(height[r] >= rightmax) rightmax = height[r];
                else cnt += rightmax - height[r];
                r--;
            }
        }
        return cnt;
    }
};