class Solution {
public:
    void dfs(vector<vector<int>>& land, int i, int j) {
        land[i][j] = 0;
        if (i>0 && land[i-1][j] == 1) {
            dfs(land, i-1, j);
        }
        if (j>0 && land[i][j-1] == 1) {
            dfs(land, i, j-1);
        }
        if (i<land.size()-1 && land[i+1][j] == 1) {
            dfs(land, i+1, j);
        }
        if (j<land[0].size()-1 && land[i][j+1] == 1) {
            dfs(land, i, j+1);
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size(), m=land[0].size();
        vector<vector<int>> ans;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (land[i][j] == 1) {
                    int _i = i, _j = j;
                    while (_j+1<m && land[_i][_j+1] == 1) {
                        ++_j;
                    }
                    while (_i+1<n && land[_i+1][j] == 1) {
                        ++_i;
                    }
                    dfs(land, i, j);
                    ans.push_back({i, j, _i, _j});
                }
            }
        }
        return ans;
    }
};