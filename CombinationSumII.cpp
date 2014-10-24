class Solution {
public:
	vector<vector<int> > ans;
	void f(vector<int> &ca, int level, int sum, vector<int> tmp) {
		if (sum == 0) {
        	if (!tmp.empty()) ans.push_back(tmp);
				return;
        }
		if (sum<ca[level] || level>=ca.size()) return;
		for (int i = level; i < ca.size(); i++) {
			if (i>level && ca[i]==ca[i-1]) continue;
			tmp.push_back(ca[i]);
			f(ca, i+1, sum-ca[i], tmp);
			tmp.pop_back();
		}
    }
	
	vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
		int len = candidates.size();
		if (len == 0) return ans;
		vector<int> tmp;
		sort(candidates.begin(), candidates.end());
		f(candidates, 0, target, tmp);
		return ans;
	}
};
