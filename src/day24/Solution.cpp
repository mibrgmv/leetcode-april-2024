class Solution {
public:
    vector<int> dp = {0, 1, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274, 504, 927, 1705};

    int tribonacci(int n) {
        if (n < 15) {
            return dp[n];
        } else {
            for (int i=15; i<n+1; ++i) {
                dp.push_back(dp[i-3] + dp[i-2] + dp[i-1]);
            }
        }
        return dp.back();
    }
};