class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
            if (gas.empty() || cost.empty()) return -1;
            int i, len, index, max, sum;
            len = gas.size();
            int *num = new int[len];
            for (i = 0; i < len; i++) num[i] = gas[i]-cost[i];
            index = 0;
            max = sum = num[0];
            for (i = 1; i < len; i++) {
                if (sum <= 0) {
                    index = i;
                    sum = num[i];
                    if (sum > max) max = sum;
                } else {
                    sum += num[i];
                    if (sum > max) max = sum;
                }
            }
            sum = num[index];
            if (sum < 0) return -1;
            for (i = (index+1)%len; i != index; i = (i+1)%len) {
                sum += num[i];
                if (sum < 0) return -1;
            }
            return index;
    }
};
