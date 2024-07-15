class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<char> h(150);
        set<char> d;
        for (int i=0; i<s.length(); ++i) {
            if (!h[s[i]] && d.find(t[i]) == d.end()) {
                h[s[i]] = t[i];
                d.insert(t[i]);
            }
            s[i] = h[s[i]];
        }
        return s == t;
    }
};