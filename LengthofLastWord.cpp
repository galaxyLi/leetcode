class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int i, st = 0, ed = 0;
        bool flag = false;
        for (i = 0; s[i] != '\0'; i++) {
            if (s[i] == ' ') {
                if (flag) {
                    ed = i;
                    flag = false;
                }
            } else {
                if (!flag) {
                    st = i;
                    flag = true;
                }
            }
        }
        if (flag) ed = i;
        return ed-st;
    }
};
