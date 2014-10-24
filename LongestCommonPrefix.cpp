class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string ans("");
        if (strs.empty()) return ans;
        bool flag;
        unsigned int minlen = 0x7fffffff, i;
        for (vector<string>::iterator iter = strs.begin(); iter != strs.end(); iter++) {
            if ((*iter).length() < minlen) minlen = (*iter).length();
        }
        for (i = minlen; i > 0; i--) {
            vector<string>::iterator iter = strs.begin();
            string tmp;
            if (iter != strs.end()) tmp = (*iter).substr(0, i);
            else break;
            flag = true;
            while (iter != strs.end()) {
                if ((*iter).compare(0, i, tmp) == 0) iter++;
                else {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans = tmp;
                break;
            }
        }
        return ans;
    }
};
