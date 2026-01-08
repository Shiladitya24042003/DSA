class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        int l = 0, r = 0;
        int jumps = 0;
        while(r < n-1) {
            for(int i = l; i <= r; i++) {
                farthest = max(farthest, i+nums[i]);
            }
            l = r+1;
            r = farthest;
            jumps++;
        }
        return jumps;
    }
};

/**
    Suppose for this test case
     [2 3 1 4 1 1 1 2]      _
      --| Take this ladder   | Jump count = 1
        --|-|-|              | Take this ladder too. Jump count = 2
          --|                | Don't take this ladder and unnecessary jumps
            --|-|-|-|        |-> All these are ladders with stairs  Take this ladder Jump count = 3
              --|            | Don't take this ladder and unnecessary jumps
                --|          | Don't take this ladder and unnecessary jumps
                  --|       _| Don't take this ladder and unnecessary jumps
    
    Thus the answer is 3
    
    Now imagine we are starting from the first index and we encounter a ladder with 1 stair
    we climb that ladder and on its way we find another ladder which has 3 stairs and 
    again we climb that ladder.Now notice we find many ladders which has less stairs we bypass them
    untill we get a bigger ladder which actually has more stairs. In this way we climb till the end index

    Obviously a DP solution does exist which is O(N^2). So we are opting for the above solution for linear time complexity of O(N) */