class Solution {
public:
	bool onechardiff(string s, string d) {
		int cnt = 0, len = s.size();
		for (int i = 0; i < len; i++) {
			if (s[i] != d[i]) cnt++;
			if (cnt > 1) return false;
		}
		return true;
	}

	void generate(vector<vector<string> > &ans, unordered_map<string, vector<string>> &father, vector<string> path, string s) {
		path.insert(path.begin(), s);
		if (father[s][0] == s) {
			ans.push_back(path);
			return;
		}
		for (int i = 0; i < father[s].size(); i++) {
			generate(ans, father, path, father[s][i]);
		}
	}

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		vector<vector<string> > ans;
		int lens = start.size();
		int lend = end.size();
		if (lens!=lend || start==end) return ans;

		if (onechardiff(start, end)) {
			vector<string> tmp;
			tmp.push_back(start);
			tmp.push_back(end);
			ans.push_back(tmp);
			return ans;
		}
		
		unordered_map<string, int> vis;
		unordered_map<string, vector<string>> father;
		bool flag = false;
		queue<string> q;
		q.push(start);
		q.push("\0");
		vis[start] = 0;
		father[start].push_back(start);
		while (!q.empty()) {
			string head = q.front();
			q.pop();
			if (head == "\0") {
				if (flag || q.empty()) break;
				else {
					q.push("\0");
					continue;
				}
			}
			for (int i = 0; i < lens; i++) {
				string tmp = head;
				for (char c = 'a'; c <= 'z'; c++) {
					if (head[i] == c) continue;
					tmp[i] = c;
					if (tmp == end) {
						father[end].push_back(head);
						/* 这次的head已经是end的父节点了，可以直接跳出两层循环 */
						i = lens;
						flag = true;
						break;
					} else if (dict.find(tmp)!=dict.end()) {
						if (vis.count(tmp) == 0) {
							vis[tmp] = vis[head]+1;
							father[tmp].push_back(head);
							q.push(tmp);
						} else if (vis[tmp] == vis[head]+1) {
							father[tmp].push_back(head);
						}
					}
				}
			}
		}
		if (father[end].empty()) return ans;
		vector<string> path;
		generate(ans, father, path, end);
		return ans;
    }
};
