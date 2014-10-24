class Solution {
public:
    string intToRoman(int num) {
        string sym[] = {"I", "V", "X", "L", "C", "D", "M"};
        int  mat[7] = {1, 5, 10, 50, 100, 500, 1000};
        int i, j, k;
        string ans;
        i = 6;
        while (num) {
            if (num >= mat[i]) {
                if (num/mat[i] == 9) {
                    ans.append(sym[i]);
                    ans.append(sym[i+2]);
                } else {
                    j = num/mat[i];
                    if (j >= 5) {
                        ans.append(sym[i+1]);
                        for (k = 0; k < j-5; k++) ans.append(sym[i]);
                    } else if (j == 4) {
                        ans.append(sym[i]);
                        ans.append(sym[i+1]);
                    } else {
                        for (k = 0; k < j; k++) ans.append(sym[i]);
                    }
                }
                num %= mat[i];
            }
            i -= 2;
        }
		return ans;
    }
};
