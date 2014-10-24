class Solution {
public:
        void f(string &s, int st, int ed) {
            char tmp;
            for (int i = 0; i <= (ed-st)/2; i++) {
                tmp = s[st+i];
                s[st+i] = s[ed-i];
                s[ed-i] = tmp;
            }
        }
        
        void del_sp(char *str) {
            bool isword = false;
            char *des = str;
            for (int i = 0; str[i]!='\0'; i++) {
                if (str[i] != ' ') {
                    *(des++) = str[i];
                    isword = true;
                } else {
                    if (isword && str[i+1]!='\0') {
                        *(des++) = str[i];
                        isword = false;
                    }
                }
            }
            *des = '\0';
        }
        
        void reverseWords(string &s) {
            int i, ws, len;
            /* delete the head and tail space */
            s.erase(0, s.find_first_not_of(" \t"));
            s.erase(s.find_last_not_of(" \t")+1);
            len = s.size();
            char tmp[len+1];
            /* delete the space in the middle */
            strcpy(tmp, s.c_str());
            del_sp(tmp);
            s = tmp;
            len = s.size();
            f(s, 0, len-1);
            ws = 0;
            for (i = 1; i < len; i++) {
                if (s[i]==' ') {
                    f(s, ws, i-1);
                    ws = i+1;
                } else if (i == len-1) f(s, ws, i);
            }
        }

};
