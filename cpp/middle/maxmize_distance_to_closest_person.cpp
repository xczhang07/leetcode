class Solution {
public:
    // time complexity is O(n), space complexity is O(1)
    int maxDistToClosest(vector<int>& seats) {
        if(seats.size() == 0) {
            return 0;
        }
        int longest = 0, begin = 0, count = 0;
        int t = 0;
        // get the zero count at the beginning.
        while(seats[t] == 0) {
            t += 1;
            begin += 1;
        }
        // get the longest zero in the middle and at the end
        for(; t < seats.size(); ++t) {
            if(seats[t] == 0) {
                count += 1;
            } else {
                longest = max(longest, count);
                count = 0;
            }
        }
        if(longest % 2 == 0) {
            longest /= 2;
        } else {
            longest = longest/2+1;
        }
        return max({begin, longest, count});
    }
};
