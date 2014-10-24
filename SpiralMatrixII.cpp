class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
    	int i, j, k;
        vector<vector<int> > ans;
        if (n == 0) return ans;
        for (i = 0; i < n; i++) {
            vector<int> tmp(n, 0);
            ans.push_back(tmp);
        }
        // check finish or not
        bool flag;
        i = j = 0;
        k = 1;
        while (true) {
			flag = true;
            /* right */
            while (j<n && ans[i][j]==0) {
                ans[i][j++] = k++;
                flag = false;
            }
            i++;
            j--;
            /* down  */
            while (i<n && ans[i][j]==0) {
                ans[i++][j] = k++;
                flag = false;
            }
            j--;
            i--;
            /* left  */
            while (j>=0 && ans[i][j]==0) {
                ans[i][j--] = k++;
                flag = false;
            }
            i--;
            j++;
            /*  up   */
            while (i>=0 && ans[i][j]==0) {
                ans[i--][j] = k++;
                flag = false;
            }
            if (flag || (k>n*n)) break;
                j++;
                i++;
        }
        return ans;
    }
};
