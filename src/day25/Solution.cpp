class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(150);
        int res = 0;
        for (auto& i : s) {
            for (int j = i - k; j <= i + k; ++j)
                dp[i] = max(dp[i], dp[j]);
            if (++dp[i] > res) res = dp[i];
        }
        return res;
    }
};