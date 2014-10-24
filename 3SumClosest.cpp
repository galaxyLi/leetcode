class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int i, j, k, len = num.size();
        int ans = 0x7fffffff;
        sort(num.begin(), num.end());
        for (i = 0; i < len-2; i++) {
            if (i!=0 && num[i-1]==num[i]) continue;
            j = i+1;
            k = len-1;
            while (j < k) {
                int sum = num[i]+num[j]+num[k];
                if (fabs(sum-target) < fabs(ans-target)) ans = sum;
                if (sum < target) j++;
                else if (sum > target) k--;
                else return ans;
            }
        }
        return ans;
    }
};
