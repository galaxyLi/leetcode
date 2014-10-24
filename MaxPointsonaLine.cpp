/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if (points.empty()) return 0;
		/* y = kx+t */
		int i, j, n, ans, dup;
		n = points.size();
		ans = 0;
		unordered_map<double, int> line;
		for (i = 0; i < n; i++) {
			line.clear();
			line[INT_MAX] = 0;
			dup = 1;
			for (j = 0; j!=i && j<n; j++) {
				if (points[i].x==points[j].x && points[i].y==points[j].y) {
					dup++;
					continue;
				}
				double k = points[i].x==points[j].x ? INT_MAX:((double)points[i].y-points[j].y)/(points[i].x-points[j].x);
				line[k]++;
			}
			unordered_map<double, int>::iterator iter;
			for (iter = line.begin(); iter != line.end(); iter++) {
				if (iter->second+dup > ans) ans = iter->second+dup;
			}
		}
		return ans;
    }
};
