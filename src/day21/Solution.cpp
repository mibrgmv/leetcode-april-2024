class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjList(n, vector<int>());
        for (auto& e : edges) {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        vector<bool> colors(n, false);
        colors[source] = true;
        queue<int> q;
        q.push(source);
        while (!q.empty()) {
            source = q.front();
            if (source == destination)
                return true;
            q.pop();
            for (int v: adjList[source]) {
                if (!colors[v]) {
                    q.push(v);
                    colors[v] = true;
                }
            }
        }
        return false;
    }
};