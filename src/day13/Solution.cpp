class Solution {
private:
    int largestArea(int n, vector<int>& v) {
        int ans=0;
        for (int i=0; i<n; ++i) {
            int width=1;
            for (int j=i+1; j<n && v[j]>= v[i]; ++j, ++width) { }
            for (int j=i-1; j>=0 && v[j]>= v[i]; --j, ++width) { }
            ans = (v[i]*width>ans) ? v[i]*width : ans;
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> histogram(matrix[0].size(), 0);
        int n=matrix.size(), m=matrix[0].size(), ans=0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (matrix[i][j] == '0') {
                    histogram[j] = 0;
                } else {
                    histogram[j]++;
                }
            }
            ans = max(ans, largestArea(m, histogram));
        }
        return ans;
    }
};