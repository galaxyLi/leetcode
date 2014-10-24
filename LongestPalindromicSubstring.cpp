class Solution {
public:
    string longestPalindrome(string s) {
		int i, j, n, maxLen = 0;
        n = s.length();
        if (n <= 1) return s;

        bool P[1001][1001];
        const char * ptr = s.data();
        for (i = 0; i < n; i++){
            P[i][i] = true;
        }

        string retval;
        int st,le;
        for (i = 0; i < n-1; i++){
            P[i][i+1] = (ptr[i] == ptr[i+1]);
            if (P[i][i+1]){
                st = i;
                le = 2;
            }
        }

        for (i = 2; i < n; i++){
            for (j = 0; j < n-i; j++){
                P[j][j+i] = P[j+1][j+i-1] && (ptr[j] == ptr[j+i]);

                if (P[j][j+i] && maxLen < i+1){
                    maxLen = i+1;
                    st = j;
                    le = i+1;
                }
            }
        }
        return s.substr(st,le);
    }
};
