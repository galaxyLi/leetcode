class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ans;
        if (numbers.empty()) return ans;
        int i;
        unordered_map<int, int> hash;
        for (i = 0; i < numbers.size(); i++) hash[numbers[i]] = i;
        for (i = 0; i < numbers.size(); i++) {
            int delta = target-numbers[i];
            if (hash.find(delta)!=hash.end() && hash[delta]>i) {
                ans.push_back(i+1);
                ans.push_back(hash[delta]+1);
                break;
            }
        }
        return ans;
    }
};
