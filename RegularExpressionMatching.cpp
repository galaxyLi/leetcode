class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (!s && !p) return true;
        if (!s || !p || *p=='*') return false;
        
        if (*p == '\0') return *s == '\0';
        if (*(p+1) != '*') {
            if (*s == '\0') return false;
            if ((*p!='.') && (*p!=*s)) return false;
            return isMatch(s+1, p+1);
        } else {
            unsigned int slen = strlen(s);
            if (isMatch(s, p+2)) return true;
            for (int i = 0; i < slen; i++) {
                if ((*p!='.') && (*p!=*(s+i))) return false;
                if (isMatch(s+i+1, p+2)) return true;
            }
            return false;
        }
    }
};
