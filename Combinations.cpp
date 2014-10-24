class Solution {
public:
	vector<vector<int> > ans;
	void f(int s, int e, int dept, vector<int> tmp) {
		if (dept == 0) {
			if (!tmp.empty()) ans.push_back(tmp);
			return;
		}
		for (int i = s; i <= e; i++) {
			tmp.push_back(i);
			f(i+1, e, dept-1, tmp);
			tmp.pop_back();
		}

    }

	vector<vector<int> > combine(int n, int k) {
		if (n==0 || k==0 || n<k) return ans;
		vector<int> tmp;
		f(1, n, k, tmp);
		return ans;
	}
};
