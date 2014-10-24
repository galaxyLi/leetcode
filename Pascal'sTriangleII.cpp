class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans, back;
        if (rowIndex < 0) return ans;
        ans.push_back(1);
        for (int i = 1; i <= rowIndex; i++) {
        	back = ans;
        	ans.clear();
        	for (int j = 0; j <= back.size(); j++) {
        		int l = (j == 0) ? 0:back[j-1];
        		int r = (j == back.size()) ? 0:back[j];
        		ans.push_back(l+r);
        	}
        }
        return ans;
    }
};
