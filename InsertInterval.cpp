/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		if (intervals.empty()) {
			intervals.insert(intervals.begin(), newInterval);
			return intervals;
		}
		int l, m, r, left, right, len;
		Interval &dest = newInterval;
		len = intervals.size();

		l = 0, r = len-1;
		while (l <= r) {
			m = (l+r)/2;
			if (intervals[m].start <= dest.start) l = m+1;
			else r = m-1;
		}
		left = l;

		l = 0, r = len-1;
		while (l <= r) {
			m = (l+r)/2;
			if (intervals[m].end < dest.end) l = m+1;
			else r = m-1;
		}
		right = r;
		if(right+1<len && intervals[right+1].start<=dest.end)
			dest.end = max(dest.end, intervals[++right].end);

		if(left-1>=0 && dest.start<=intervals[left-1].end)
			dest.start = min(dest.start, intervals[--left].start);
		if(right+1 >= left){
			intervals.insert(intervals.begin()+left, dest);
			// [)×ó±ÕÓÒ¿ªÇø¼ä so, right should plus 2
			intervals.erase(intervals.begin()+left+1, intervals.begin()+right+2);
		}
		return intervals;
    }
};
