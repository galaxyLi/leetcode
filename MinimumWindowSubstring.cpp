class Solution {
    public:
        string minWindow(string S, string T) {
            string ans;
            if (S.empty() || T.empty()) return ans;
            int lens = S.size();
            int lent = T.size();
            int i, j, cnt;
            /* have duplicate element in T, so need count */
            map<char, int> cmap;
            map<char, int> tmap;
            queue<int> pos;
            for (i = 0; i < lent; i++) cmap[T[i]]++;
            cnt = 0;
            for (i = 0; i < lens; i++) {
                if (cmap.count(S[i])) {
                    if (tmap[S[i]] < cmap[S[i]]) {
                        pos.push(i);
                        tmap[S[i]]++;
                        if (tmap[S[i]] == cmap[S[i]]) cnt += cmap[S[i]];
                        if (cnt == lent) {
                            int beg = pos.front();
                            pos.pop();
                            tmap[S[beg]]--;
                            if (ans.empty()) ans = S.substr(beg, i-beg+1);
                            else if (i-beg+1 < ans.size()) ans = S.substr(beg, i-beg+1);
                            while (tmap[S[beg]] >= cmap[S[beg]]) {
                                beg = pos.front();
                                pos.pop();
                                tmap[S[beg]]--;
                                if (i-beg+1 < ans.size()) ans = S.substr(beg, i-beg+1);
                            }
                            cnt -= cmap[S[beg]];
                        }
                    } else {
                        pos.push(i);
                        tmap[S[i]]++;
                    }
                }
            }
            return ans;
        }
};
