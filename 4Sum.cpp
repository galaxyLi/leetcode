class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ans;
        vector<int> tmp;
        if (num.empty()) return ans;
        int i, j, l, r, len = num.size();
        sort(num.begin(), num.end());
        for (i = 0; i < len-3; i++) {
            if (i!=0 && num[i-1]==num[i]) continue;
            int first = i+1;
            for (j = i+1; j < len-2; j++) {
                if (j!=first && num[j]==num[j-1]) continue;
                l = j+1;
                r = len-1;
                while (l < r) {
                    int sum = num[i]+num[j]+num[l]+num[r]-target;
                    if (sum < 0) l++;
                    else if (sum > 0) r--;
                    else {
                        tmp.clear();
                        tmp.push_back(num[i]);
                        tmp.push_back(num[j]);
                        tmp.push_back(num[l]);
                        tmp.push_back(num[r]);
                        ans.push_back(tmp);
                        int pos = l;
                        while (l<r && num[pos]==num[l]) l++;
                    }
                }
            }
        }
        return ans;
    }
};
