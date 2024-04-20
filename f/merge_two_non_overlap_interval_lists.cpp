Questions: https://leetcode.com/discuss/interview-question/124616/
https://leetcode.com/discuss/interview-question/883800/facebook-phone-merge-sorted-arrays-merge-two-sorted-interval-lists

vector<pair<int, int>> mergeNonOverlapIntervals(vector<pair<int,int>>& list1, vector<pair<int,int>>& list2) {
    vector<pair<int, int>> ret;
    int start = INT_MIN;
    int end = INT_MIN;
    int i = 0, j = 0;
    while(i < list1.size() || j < list2.size()) {
        pair<int, int> curr;
        if(i == list1.size()) {
            curr = list2[j];
            ++j;
        } else if(j == list2.size()) {
            curr = list1[i];
            ++i;
        } else {
            if(list1[i].first < list2[j].first) {
                curr = list1[i];
                ++i;
            } else {
                curr = list2[j];
                ++j;
            }
        }
        // merge logic, no overlap
        if(curr.first > end) {
            if(end != INT_MIN) {
                ret.push_back({start, end});
            }
            start = curr.first;
            end = curr.second;
        } else {
            end = max(end, curr.second);
        }
    }
    if(start != INT_MIN) {
        ret.push_back({start, end});
    }
    return ret;
}

# Version2, easy for understanding

void merge(vector<pair<int,int>>& list, pair<int, int> interval) {
    if(list.size() == 0) {
        list.push_back(interval);
        return;
    }
    if(list.back().second < interval.first) {
        list.push_back(interval);
    } else {
        list.back().second = max(list.back().second, interval.second);
    }
    return;
}

vector<pair<int, int>> mergeNonOverlapIntervalsVer2(vector<pair<int,int>>& list1, vector<pair<int,int>>& list2) {
    vector<pair<int, int>> ret;
    int i = 0, j = 0;
    while(i < list1.size() && j < list2.size()) {
        if(list1[i].first <= list2[j].first) {
            merge(ret, list1[i]);
            ++i;
        } else {
            merge(ret, list2[j]);
            ++j;
        }
    }
    while(i < list1.size()) {
        merge(ret, list1[i]);
        ++i;
    }
    while(j < list2.size()) {
        merge(ret, list2[j]);
        ++j;
    }
    return ret;
}
