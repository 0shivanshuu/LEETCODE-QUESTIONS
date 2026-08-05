class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        
        vector<vector<int>> adj(n);

        for (auto it : invocations) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
        }

        vector<int> suspicious(n, 0);
        queue<int> q;

        q.push(k);
        suspicious[k] = 1;

        while (!q.empty()) {
            int method = q.front();
            q.pop();

            for (int next : adj[method]) {
                if (suspicious[next] == 0) {
                    suspicious[next] = 1;
                    q.push(next);
                }
            }
        }

        for (auto it : invocations) {
            int u = it[0];
            int v = it[1];

            if (suspicious[u] == 0 && suspicious[v] == 1) {
                
                vector<int> ans;

                for (int i = 0; i < n; i++) {
                    ans.push_back(i);
                }

                return ans;
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (suspicious[i] == 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};