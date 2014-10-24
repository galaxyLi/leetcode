class Solution {
public:
    string justify(vector<string> &vec, int sum, int L) {
        int i, j, k, len = vec.size();
        string res;
        if (len == 1) {
            res.append(vec[0]);
            for (i = 0; i < L-sum; i++) res.append(" ");
            return res;
        }
        vector<int> space(len-1, 1);
        k = L-sum;
        i = 0;
        while (k-- > 0) {
            space[i++]++;
            if (i == len-1) i = 0;
        }
        for (i = 0; i < len-1; i++) {
            res.append(vec[i]);
            for (j = 0; j < space[i]; j++) res.append(" ");
        }
        res.append(vec[len-1]);
        return res;
    }
    vector<string> fullJustify(vector<string> &words, int L) {
        int i, j, sum, len;
        len = words.size();
        vector<string> ans, vec;
        if (len==0) return ans;
        sum = 0;
        for (i = 0; i < len; i++) {
            int l = words[i].size()+1;
            if (sum+l-1 <= L) {
                sum += l;
                vec.push_back(words[i]);
            } else {
                ans.push_back(justify(vec, sum-1, L));
                vec.clear();
                vec.push_back(words[i]);
                sum = l;
            }
        }
        string last;
        for (i = 0; i < vec.size(); i++) {
            last.append(vec[i]);
            if (vec[i].size() < L) last.append(" ");
        }
        for (i = 0; i < L-sum; i++) last.append(" ");
        ans.push_back(last);
        return ans;
    }
};
