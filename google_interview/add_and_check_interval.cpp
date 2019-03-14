5. 设计两个api，add(int[] range), check(int key) - if key exists in any of the ranges,
then return true, otherwise false (call check() would be much more frequent than add(), 意思就是check()的时候，效率要高一些)

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class AddCheck {
public:
	vector<Interval> insert(Interval newInterval) 
	{
		if (intervals.size() == 0)
		{
			intervals.push_back(newInterval);
			return intervals;
		}
		auto iter1 = intervals.begin();
		while (iter1 != intervals.end())
		{
			if (newInterval.end < iter1->start)
			{
				intervals.insert(iter1, newInterval);
				return intervals;
			}
			else if (newInterval.start > iter1->end)
				++iter1;
			else
			{
				newInterval.start = min(newInterval.start, iter1->start);
				newInterval.end = max(newInterval.end, iter1->end);
				iter1 = intervals.erase(iter1);
			}
		}
		intervals.push_back(newInterval);
		return intervals;
	}

	bool check(int key)
	{
		if (intervals.size() == 0)
			return false;
		int n = intervals.size();
		if (key < intervals[0].start || key > intervals[n - 1].end)
			return false;
		int l = 0;
		int r = n - 1;
		int m = 0;
		while (l <= r)
		{
			m = l + (r - l) / 2;
			if (intervals[m].start <= key)
			{
				if (intervals[m].start == key)
					return true;
				if (m == n - 1)
					return true;
				else if (m < n - 1 && intervals[m + 1].start > key)
					break;
				else
					l = m + 1;
			}
			else /* intervals[m].start > key, check left size */
				r = m - 1;
		}

		if (intervals[m].end >= key)
			return true;
		return false;
	}

private:
	vector<Interval> intervals;
};
