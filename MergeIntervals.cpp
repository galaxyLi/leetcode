/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
static bool mycmp(const Interval &a, const Interval &b) {
	if (a.start == b.start) return a.end < b.end;
	return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
		vector<Interval> ans;
		if (intervals.empty()) return ans;
        sort(intervals.begin(), intervals.end(), mycmp);
		int i, len = intervals.size();
		Interval pre = intervals[0];
		for (i = 1; i < len; i++) {
			if (intervals[i].start <= pre.end) {
				if (pre.end < intervals[i].end) pre.end = intervals[i].end;
			} else {
				ans.push_back(pre);
				pre = intervals[i];
			}
		}
		ans.push_back(pre);
		return ans;
    }
};
