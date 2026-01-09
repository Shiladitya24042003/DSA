class Solution {
public:
    bool checkValidString(string s) {
        int max = 0;
        int min = 0;
        for(auto it: s) {
            if(it == '(') {
                max++;
                min++;
            }
            else if(it == '*') {
                max++;
                min--;
            }
            else {
                max--;
                min--;
            }
            if(min < 0) min = 0;
            if(max < 0) return false;
        }
        return min == 0;
    }
};