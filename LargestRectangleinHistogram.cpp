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
                int area_with_top = height[tp]*(stk.empty() ? i:(i-stk.top()-1));
                max_area = area_with_top>max_area ? area_with_top:max_area;
            }
        }
        while (!stk.empty()) {
            tp = stk.top();
            stk.pop();
            int area_with_top = height[tp]*(stk.empty() ? len:(len-stk.top()-1));
            max_area = area_with_top>max_area ? area_with_top:max_area;
        }
        return max_area;
    }
};
