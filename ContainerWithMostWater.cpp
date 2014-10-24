class Solution {
public:
    int maxArea(vector<int> &height) {
        unsigned int max_w = 0;
		vector<int>::size_type l, r;
		l = 0;
		r = height.size()-1;
		while (l < r) {
			max_w = max(max_w, (r-l)*min(height[l], height[r]));
			if (height[l] < height[r]) l++;
			else r--;
		}
		return max_w;
    }
};
