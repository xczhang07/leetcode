class Solution {
public:
    // time complexity is O(n), space complexity is O(1)
    int maxDistToClosest(vector<int>& seats) {
        int begin = 0, t = 0, longest = 0;
        while(seats[t] == 0) {
            t += 1;
            begin += 1;
        }
        int count = 0;
        for(; t < seats.size(); ++t) {
            if(seats[t] == 0) {
                count += 1;
            } else {
                longest = max(count, longest);
                count = 0;
            }
        }
        if(longest%2 == 0) {
            longest /= 2;
        } else {
            longest = longest/2+1;
        }
        return max({begin, longest, count});
    }
};


Time complexity is: O(n)
Space complexity is: O(1)
