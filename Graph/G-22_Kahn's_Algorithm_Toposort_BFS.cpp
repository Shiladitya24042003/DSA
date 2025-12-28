class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        vector<int> indg(V, 0);
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            indg[v]++;
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
        
        return ans;
    }
};