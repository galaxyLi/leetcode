class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ret;
        if (strs.empty()) return ret;
        unordered_map<string, vector<string> > smap;
        int i, len = strs.size();
        for (i = 0; i < len; i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            smap[tmp].push_back(strs[i]);
        }
        for (unordered_map<string, vector<string> >::iterator iter = smap.begin(); iter != smap.end(); iter++) {
            if (iter->second.size() > 1) {
                ret.insert(ret.end(), iter->second.begin(), iter->second.end());
            }
        }
        return ret;
    }
};
