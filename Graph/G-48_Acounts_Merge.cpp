class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if(node == parent[node]) {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int> mapMailNode;
        int n = accounts.size();
        DisjointSet ds(n);
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                }
                else {
                    int u = i, v = mapMailNode[mail];
                    ds.unionBySize(u, v);
                }
            }
        }

        vector<string> mapNodeMail[n];
        for(auto it: mapMailNode) {
            string mail = it.first;
            int node = it.second;
            int parent = ds.findUPar(node);
            mapNodeMail[parent].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++) {
            if(mapNodeMail[i].size() == 0) continue;
            sort(mapNodeMail[i].begin(), mapNodeMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mapNodeMail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};