class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];
        vector<int> time(n+1, 1e9);
        set<pair<int, int>> st;
        for(auto it: times) {
            int u = it[0];
            int v = it[1];
            int t = it[2];
            adj[u].push_back({v, t});
        }

        st.insert({0, k});
        time[k] = 0;

        while(!st.empty()) {
            auto it = *(st.begin());
            int node = it.second;
            int t = it.first;
            st.erase(it);

            for(auto it: adj[node]) {
                int adjNode = it.first;
                int adjT = it.second;

                if(t + adjT < time[adjNode]) {
                    if(time[adjNode] != 1e9)
                        st.erase({time[adjNode], adjNode});
                    
                    time[adjNode] = t + adjT;
                    st.insert({time[adjNode], adjNode});
                }
            }
        }

        int ans = -1;
        for(int i = 1; i <= n; i++) {
            if(time[i] == 1e9) return -1;
            ans = max(ans, time[i]);
        }
        return ans;
    }
};