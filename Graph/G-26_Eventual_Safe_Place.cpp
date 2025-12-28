class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> revadj[n];
        vector<int> indg(n, 0);
        /*
        Intuition & Logic:
        ------------------
        A node is called "eventually safe" if every path starting from it ends at a terminal node
        (a node with no outgoing edges). Nodes that are part of a cycle or can reach a cycle are NOT safe.

        Key Idea:
        ---------
        Instead of directly detecting cycles, we reverse the graph and apply a Topological Sort–like process.

        Steps:
        1. Reverse all edges of the graph.
        - If there is an edge u -> v in the original graph,
            we add v -> u in the reversed graph.
        2. Compute indegree for each node in the ORIGINAL graph.
        - Nodes with indegree 0 in this context are terminal nodes
            (they have no outgoing edges).
        3. Push all terminal nodes into a queue.
        4. Perform BFS (Kahn’s algorithm style):
        - Remove a safe node from the queue.
        - For every node pointing to it (using reversed graph),
            reduce its indegree.
        - If any node’s indegree becomes 0, it means all its outgoing
            paths now lead to safe nodes → it is also safe.
        5. Collect all such nodes and sort them.

        Why it works:
        -------------
        Nodes involved in cycles will never get indegree 0,
        so they are automatically excluded. Only nodes that eventually
        lead to terminal nodes survive the process.

        Time Complexity: O(V + E)
        Space Complexity: O(V + E)
        */

        for(int i = 0; i < n; i++) {
            for(auto it: graph[i]) {
                revadj[it].push_back(i);
                indg[i]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indg[i] == 0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it: revadj[node]) {
                indg[it]--;
                if(indg[it] == 0) q.push(it);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};