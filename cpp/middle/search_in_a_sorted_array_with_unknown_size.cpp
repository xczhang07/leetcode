// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int e = 1;
        while(reader.get(e) < target)
            e *= 2;
        
        int left = 0;
        int right = e;
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(reader.get(mid) == target)
                return mid;
            else if(reader.get(mid) < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};
