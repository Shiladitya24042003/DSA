class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<int> adj[V];
        vector<int> indg(V,0);
        for(auto it: prerequisites) {
            adj[it[1]].push_back(it[0]);
            indg[it[0]]++;
        }

        
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indg[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it: adj[node]) {
                indg[it]--;
                if(indg[it] == 0) q.push(it);
            }
        }
        if(ans.size() == V) return ans;
        return {};
    }
};