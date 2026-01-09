class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1;
        int sum = 1;
        while(i < n) {
            if(ratings[i-1] == ratings[i]) {
                sum += 1;
                i++;
                continue;
            }
            int peek = 1;
            while(i<n && ratings[i-1] < ratings[i]) {
                peek += 1;
                sum += peek;
                i++;
            }
            int down = 1;
            while(i < n && ratings[i-1] > ratings[i]) {
                sum += down;
                down += 1;
                i++;
            }

            if(peek < down) {
                sum += down - peek;
            }
        }
        return sum;
    }
};