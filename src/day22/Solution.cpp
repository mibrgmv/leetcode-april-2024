class Solution {
private:
    vector<vector<string>> adjList = vector<vector<string>> (10000);
    vector<int> dist = vector<int> (10000, 10001);
    unordered_set<string> ds;

    string moveUp(string s, int pos) {
        if (s[pos] == '9') {
            s[pos] = '0';
        } else {
            s[pos]++;
        }
        return s;
    }

    string moveDown(string s, int pos) {
        if (s[pos] == '0') {
            s[pos] = '9';
        } else {
            s[pos]--;
        }
        return s;
    }

    int bfs(string s, string& d) {
        dist[stoi(s)] = 0;
        queue<string> q;
        q.push(s);
        while (!q.empty()) {
            string u = q.front();
            q.pop();
            if (ds.find(u) != ds.end()) {
                continue;
            }
            if (u == d) {
                return dist[stoi(u)];
            }
            for (int pos=0; pos<4; ++pos) {
                for (bool up : {true, false}) {
                    string v = (up) ? moveUp(u, pos) : moveDown(u, pos);
                    if (dist[stoi(v)] == 10001) {
                        dist[stoi(v)] = dist[(stoi(u))] + 1;
                        q.push(v);
                    }
                }
            }
        }
        return -1;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        ds = unordered_set<string> (deadends.begin(), deadends.end());
        return bfs("0000", target);
    }
};