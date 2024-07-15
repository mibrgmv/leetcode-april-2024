class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for (auto c: num) {
            while (!s.empty() && s.top() > c && k > 0) {
                --k;
                s.pop();
            }
            s.push(c);
        }
        while (k > 0 && !s.empty()) {
            s.pop();
            --k;
        }
        string ans;
        while(!s.empty()) {
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        for (int i=0; i<ans.size(); ) {
            if (ans[i] != '0') {
                break;
            }
            ans.erase(0, 1);
        }
        return (ans == "") ? "0" : ans;
    }
};