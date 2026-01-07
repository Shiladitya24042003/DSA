class Data {
  public:
    int start;
    int end;
    int indx;
    
    Data(int start, int end, int indx) {
        this->start = start;
        this->end = end;
        this->indx = indx;
    }
};
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool comp(Data &d1, Data &d2) {
        return d1.end < d2.end;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<Data> meetings;
        for(int i = 0; i < n; i++) {
            meetings.push_back(Data(start[i], end[i], i));
        }
        
        sort(meetings.begin(), meetings.end(), comp);
        
        int cnt = 1, freeTime = meetings[0].end;
        for(auto it: meetings) {
            int newStart = it.start;
            int newEnd = it.end;
            int newindx = it.indx;
            
            if(freeTime < newStart) {
                cnt++;
                freeTime = newEnd;
            }
        }
        return cnt;
    }
};