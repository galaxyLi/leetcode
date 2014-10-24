class Solution {
public:
    string simplifyPath(string path) {
        vector<string> vec;
        int i, len = path.size();
        string tmp;
        int cnt = 0;
		for (i = 0; i < len; i++) {
            if (path[i] == '/') {
            	if (!tmp.empty()) {
                	if (tmp == "..") {
                    	if (!vec.empty()) vec.pop_back();
                    	if (!vec.empty()) vec.pop_back();
                	} else if (tmp != ".") vec.push_back(tmp);
                	tmp.clear();
            	}
            	if (!vec.empty() && vec.back()=="/") continue;
            	else vec.push_back("/");
            } else tmp.push_back(path[i]);
        }
        if (!tmp.empty()) {
        	if (tmp == "..") {
                if (!vec.empty()) vec.pop_back();
                if (!vec.empty()) vec.pop_back();
            } else if (tmp != ".") vec.push_back(tmp);
            tmp.clear();
        }
        for (i = 0; i < vec.size(); i++) {
            if (i==vec.size()-1 && vec[i]=="/") break;
            tmp.append(vec[i]);
        }
        if (tmp.empty()) tmp.append("/");
        return tmp;
    }
};
