class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        int len1 = s1.size();
        int len2 = s2.size();
        if (len1 != len2) return false;
        string t1 = s1, t2 = s2;
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        if (t1 != t2) return false;
        for (int i = 1; i < len1; i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) return true;
            if (isScramble(s1.substr(0, i), s2.substr(len2-i)) && isScramble(s1.substr(i), s2.substr(0, len2-i))) return true;
        }
        return false;
    }
};
