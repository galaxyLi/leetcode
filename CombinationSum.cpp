class Solution {
public:
    vector<vector<int> > ans;
    void f(vector<int> &candidates, int level, int sum, vector<int> tmp) {
		if (sum == 0) {
			if (!tmp.empty()) ans.push_back(tmp);
			return;
        }
        if (sum < candidates[level]) return;
        int t = sum/candidates[level];
        if (level == candidates.size()-1) {
        	if (sum%candidates[level] == 0) {
				for (int i = 0; i < t; i++)
					tmp.push_back(candidates[level]);
					ans.push_back(tmp);
			}
			return;
		}
		for (int i = 0; i <= t; i++) {
			if (i > 0) tmp.push_back(candidates[level]);
				f(candidates, level+1, sum-i*candidates[level], tmp);
        }
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		int len = candidates.size();
		if (len == 0) return ans;
		vector<int> tmp;
		sort(candidates.begin(), candidates.end());
		f(candidates, 0, target, tmp);
		return ans;
	}
};
