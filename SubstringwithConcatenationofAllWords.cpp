class Solution {
    public:
        vector<int> findSubstring(string S, vector<string> &L) {
            vector<int> ans;
            if (S.empty() || L.empty()) return ans;
            int lenl = L.size();
            int lens = S.size();
            int len  = L[0].size();
            int i, j, k;
            bool flag;
            unordered_map<string, int> smap;
            unordered_map<string, int> cmap;
            for (i = 0; i < lenl; i++) smap[L[i]]++;
            for (i = 0; i < len; i++) {
                for (j = i; j <= lens-len*lenl; j += len) {
                    k = j;
                    string sub = S.substr(j, len);
                    while (smap.count(sub)>0 && j<=lens-len) {
                        cmap[sub]++;

                        if (cmap[sub] > smap[sub]) {
                            string tmp = S.substr(k, len);
                            while (tmp != sub) {
                                cmap[tmp]--;
                                k += len;
                                tmp = S.substr(k, len);
                            }
                            cmap[sub]--;
                            k += len;
                        }

                        j += len;
                        if (j-k == lenl*len) {
                            ans.push_back(k);
                            string tmp = S.substr(k, len);
                            cmap[tmp]--;
                            k += len;
                        }
                        sub = S.substr(j, len);
                    }
                    cmap.clear();
                }
            }
            return ans;
        }
};
