class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > ans;
        ans.push_back(vector<int>());
        sort(S.begin(), S.end());
        int i, j, curr_size, pre_size;
        vector<int> d;
        for (i = 0; i < S.size(); i++) {
            curr_size = ans.size();
            if (i>0 && S[i]==S[i-1]) {
            	j = pre_size;
            } else j = 0;
            while (j < curr_size) {
                d = ans[j];
                d.push_back(S[i]);
                ans.push_back(d);
                j++;
            }
        	pre_size = curr_size;
    	}
        return ans;
    }
};
