class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ans;
        ans.push_back(vector<int>());
        sort(S.begin(), S.end());
        int curr_size;
        vector<int> d;
        for (int i = 0; i < S.size(); i++) {
            curr_size = ans.size();
            for (int j = 0; j < curr_size; j++) {
                d = ans[j];
                d.push_back(S[i]);
                ans.push_back(d);
            }
        }
        return ans;
    }
};
