class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st, z;
        int n = s.length();
        for (int i=0; i<n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == '*') {
                z.push(i);
            } else if (s[i] == ')' && !st.empty()) {
                st.pop();
            } else if (s[i] == ')' && !z.empty()) {
                z.pop();
            } else {
                return false;
            }
        }
        while (!st.empty()) {
            if (!z.empty() && z.top() > st.top()) {
                st.pop();
                z.pop();
            } else {
                return false;
            }
        }
        return true;
    }
};