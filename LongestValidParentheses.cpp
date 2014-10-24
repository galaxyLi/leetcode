class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.empty()) return 0;
        stack<char> stk;
        vector<int> vec;
        int i, j, max, l, len = s.size();
        for (i = 0; i < len; i++) {
            if (stk.empty() || s[i]=='(') {
                stk.push(s[i]);
                vec.push_back(i);
            } else {
				if (stk.top() == '(') {
                stk.pop();
                vec.pop_back();
            	} else {
                	stk.push(s[i]);
                	vec.push_back(i);
            	}
        	}
        }
        l = vec.size();
        if (l == 0) return len;
        max = vec[0];
        for (i = 1; i < l; i++) {
            j = vec[i]-vec[i-1]-1;
            max = j>max ? j:max;
        }
        j = len-vec[l-1]-1;
        max = j>max ? j:max;
        return max;
    }
};
