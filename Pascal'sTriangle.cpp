class Solution {
public:
    vector<vector<int> > generate(int numRows) {
    	vector<vector<int> > ans;
        if (numRows <= 0) return ans;
        vector<int> tmp;
        tmp.push_back(1);
        ans.push_back(tmp);
        int i, j;
        for (i = 1; i < numRows; i++) {
        	tmp.clear();
        	for (j = 0; j <= i; j++) {
        		int l = (j == 0) ? 0:ans[i-1][j-1];
        		int r = (j == i) ? 0:ans[i-1][j];
        		tmp.push_back(l+r);
        	}
        	ans.push_back(tmp);
        }
        return ans;
    }
};
