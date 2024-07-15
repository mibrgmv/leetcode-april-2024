class Solution {
private:
    vector<pair<int,int>> ans;
    vector<vector<int>> adj;
    vector<int> res;

    pair<int,int> dfs1(int s, int d) {
        int a = 0, b = 0;
        for (int v : adj[s]) {
            if (v == d) {
                continue;
            }
            pair<int, int> p = dfs1(v, s);
            a += p.first;
            b += p.second;
        }

        return ans[s]={a + b, b + 1};
    }

    void dfs2(int s, int d){
        if (d == -1) {
            res[s] = ans[s].first;
        } else {
            res[s] = res[d] - ans[s].second + (ans[0].second - ans[s].second);
        }
        for (int v : adj[s]){
            if (v == d) {
                continue;
            }
            dfs2(v, s);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        ans.resize(n);
        res.resize(n);
        for (auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs1(0,-1);
        dfs2(0,-1);
        return res;
    }
};