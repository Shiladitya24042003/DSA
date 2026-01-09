class Solution {
  private:
    static bool comp(const pair<int, int> &p1, pair<int, int> &p2) {
        return p1.second> p2.second;
    }
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size();
        vector<pair<int, int>> arr;
        int limit = 0;
        for(int i = 0; i < n; i++) {
            arr.push_back({deadline[i], profit[i]});
            limit = max(limit, deadline[i]);
        }
        sort(arr.begin(), arr.end(), comp);
        int cnt = 0;
        
        vector<int> v(limit+1, -1);
        int prof = 0;
        for(auto it: arr) {
            int i = it.first;
            while(i > 0 && v[i] != -1) {
                i--;
            }
            if(i > 0) {
                v[i] = 1;
                cnt++;
                prof += it.second;
            }
        }
        
        return {cnt, prof};
    }
};



/**
        Time complexity of this code is O(N*M)
        We can further optimise it using the Disjoint Set.
        To understand the logic head over to the follwing link
        https://www.geeksforgeeks.org/dsa/job-sequencing-problem-using-disjoint-set/     
        
        and read the "How come find() of disjoint set returns the latest available time slot? "  of the article 
*/