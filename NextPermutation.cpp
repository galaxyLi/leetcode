class Solution {
public:
        void nextPermutation(vector<int> &num) {
            int i, j, st, ed, len = num.size();
            bool flag = false;
            st = -1;
            for (i = len-1; i > 0; i--) {
                for (j = i-1; j >= 0; j--) {
                    if (num[i] > num[j]) {
                        flag = true;
                        if (j > st) {
                            st = j;
                            ed = i;
                        }
                        break;
                    }
                }
            }
            if (flag) {
                int tmp = num[st];
                num[st] = num[ed];
                num[ed] = tmp;
                sort(num.begin()+st+1, num.end());
            } else sort(num.begin(), num.end());
        }
};
