class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ans;
        vector<int> tmp;
        if (num.empty()) return ans;
        int i, j, k, len = num.size();
        sort(num.begin(), num.end());
        for (i = 0; i < len-2; i++) {
            if (i!=0 && num[i-1]==num[i]) continue;
            j = i+1;
            k = len-1;
            while (j < k) {
                int sum = num[i]+num[j]+num[k];
                if (sum < 0) j++;
                else if (sum > 0) k--;
                else {
                    tmp.clear();
                    tmp.push_back(num[i]);
                    tmp.push_back(num[j]);
                    tmp.push_back(num[k]);
                    ans.push_back(tmp);
                    int pos = j;
                    while (j<k && num[pos]==num[j]) j++;
                }
            }
        }
        return ans;
    }
};
