class Solution {
public:
    bool isGood(string s) {
        for (int i=0; i<s.size(); ++i) {
            if (abs(s[i] - s[i+1]) == 32) {
                return false;
            }
        }
        return true;
    }

    string makeGood(string s) {
        while (!isGood(s)) {
            int n = s.size();
            for (int i=0; i<n-1;) {
                if (abs(s[i] - s[i + 1]) != 32) {
                    ++i;
                } else {
                    s.erase(s.begin() + i, s.begin() + i + 2);
                }
            }
        }
        return s;
    }
};