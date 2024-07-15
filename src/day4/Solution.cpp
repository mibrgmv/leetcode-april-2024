class Solution {
public:
    int maxDepth(string s) {
        int curr = 0, ans = -1;
        for (char c: s) {
            if (c == '(') {
                ++curr;
            } else if (c == ')') {
                --curr;
            }

            ans = max(curr, ans);
        }
        return ans;
    }
};