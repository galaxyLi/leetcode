class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int i, len, max_area, tp;
        stack<int> stk;
        len = height.size();
        i = max_area = 0;
        while (i < len) {
            if (stk.empty() || height[stk.top()]<=height[i])
                stk.push(i++);
            else {
                tp = stk.top();
                stk.pop();
                /* Here must be i-stk.top()-1, only this can caculate area before tp */
                int area_with_top = height[tp]*(stk.empty() ? i:(i-stk.top()-1));
                max_area = area_with_top>max_area ? area_with_top:max_area;
            }
        }
        while (!stk.empty()) {
            tp = stk.top();
            stk.pop();
            /* Here must be i-stk.top()-1, only this can caculate area before tp */
            int area_with_top = height[tp]*(stk.empty() ? len:(len-stk.top()-1));
            max_area = area_with_top>max_area ? area_with_top:max_area;
        }
        return max_area;
    }

    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty()) return 0;
        int i, j;
        int row = matrix.size(), colum = matrix[0].size();
        vector<vector<int> > hgt;
        for (i = 0; i < row; i++) {
            vector<int> tmp;
            for (j = 0; j < colum; j++) {
                if (i == 0) {
					tmp.push_back(matrix[i][j]-'0');
                } else {
                    if (matrix[i][j] == '1') tmp.push_back(hgt[i-1][j]+1);
                    else tmp.push_back(0);
                }
            }
            hgt.push_back(tmp);
        }

        int max = 0;
        for (i = 0; i < row; i++) {
			int ret = largestRectangleArea(hgt[i]);
            max = ret>max ? ret:max;
		}
        return max;
    }
};
