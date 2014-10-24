class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        int lens = start.size();
        int lend = end.size();
        if (lens!=lend || start==end) return 0;
        map<string, int> dis;
        queue<string> q;
        q.push(start);
        dis[start] = 1;
        while (!q.empty()) {
            string head = q.front();
            q.pop();
            int headdist = dis[head];
            for (int i = 0; i < lens; i++) {
                string tmp = head;
                for (char c = 'a'; c <= 'z'; c++) {
                    if (head[i] == c) continue;
                    tmp[i] = c;
                    if (tmp == end) return headdist+1;
                    if (dict.find(tmp)!=dict.end() && dis.find(tmp)==dis.end()) {
                        dis[tmp] = dis[head]+1;
                        q.push(tmp);
                    }
                }
            }
        }
        return 0;
    }
};
