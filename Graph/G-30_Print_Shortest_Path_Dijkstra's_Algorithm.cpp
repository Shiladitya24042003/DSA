#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        set<pair<int, int>> st;
        vector<pair<int, int>> adj[n+1];
        vector<int> dist(n+1, 1e9);
        vector<int> backTrack(n+1);
        
        for(int i = 0; i < n+1; i++)
            backTrack[i] = i;
        
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        st.insert({0, 1});
        dist[1] = 0;
        while(!st.empty()) {
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);
            
            for(auto it: adj[node]) {
                int adjNode = it.first;
                int adjW = it.second;
                
                if(dis + adjW < dist[adjNode]) {
                    if(dist[adjNode] != 1e9)
                        st.erase({dist[adjNode], adjNode});
                    backTrack[adjNode] = node;
                    dist[adjNode] = dis + adjW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        vector<int> ans;
        int i = n;
        while(i >= 1) {
            ans.push_back(i);
            if(backTrack[i] == i) break;
            i = backTrack[i];
        }
        reverse(ans.begin(), ans.end());
        if(ans[0] != 1) return {-1};
        return ans;
    }
};
int main() {
    Solution obj;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(3));
    for(auto &it: edges) {
        cin >> it[0] >> it[1] >> it[2];
    }

    vector<int> ans = obj.shortestPath(n, m, edges);
    for(auto it: ans) cout<<it<<" ";
}