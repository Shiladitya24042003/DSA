class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int i = 0, j = 0;
        int cnt = 0, maxCnt = 0;
        
        while(i < n && j < n) {
            if(arr[i] <= dep[j]) {
                cnt++;
                i = i+1;
            }
            else {
                cnt--;
                j = j+1;
            }
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
};


/**
        Take this example 
        arr[] = [900, 940, 950, 1100, 1500, 1800]
        dep[] = [910, 1200, 1120, 1130, 1900, 2000]
        
                watch carefully how the events are happening
                (900, A), (910, D), (940, A), (950, A), (1100, A), (1120, D), (1130, D), (1200, D), (1500, A), (1800, A), (1900, D), (2000, D)
Platform Count = 0,1,0,1,2,3,2,1,0,1,2,1,0

        Clearly the maximum number of platforms required is 3 as the time passess
        
*/