class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        vector<vector<int>> adj(n);
        for (auto& e:edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int sz = n;
        vector<int> card(n);
        queue<int> q;
        for (int i=0;i<n;i++) {
            card[i] = adj[i].size();
        }
        for (int i=0; i<n; ++i) {
            if (card[i] == 1) {
                q.push(i);
            }
        }
        while (sz > 2) {
            int currentLeafNum = q.size();
            while (currentLeafNum--) {
                int cur = q.front();
                for (int x : adj[cur]) {
                    if (card[x]) {
                        --card[x];
                        --card[cur];
                        if (card[x] == 1) {
                            q.push(x);
                        }
                    }
                }
                q.pop();
                --sz;
            }
        }
        auto ans = vector<int>();
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};