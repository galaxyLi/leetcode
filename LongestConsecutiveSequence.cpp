class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if (num.empty()) return 0;
        sort(num.begin(), num.end());
        int max = 0, cnt = 1;
        for (int i = 1; i < num.size(); i++) {
            if (num[i] == num[i-1]) continue;
            if (num[i] == num[i-1]+1) cnt++;
            else {
				max = cnt>max ? cnt:max;
                cnt = 1;
            }
        }
        max = cnt>max ? cnt:max;
        return max;
    }
};
