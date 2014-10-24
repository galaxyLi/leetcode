class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return true;
        stack<char> sta;
        int i, len = s.length();
		sta.push(s[0]);
		for (i = 1; i < len; i++) {
			if (s[i]==')' && (!sta.empty() && sta.top()=='(')) sta.pop();
			else if (s[i]==']' && (!sta.empty() && sta.top()=='[')) sta.pop();
			else if (s[i]=='}' && (!sta.empty() && sta.top()=='{')) sta.pop();
			else sta.push(s[i]);
		}
		if (sta.empty()) return true;
		return false;
    }
};
