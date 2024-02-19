class Solution {
public:

    bool isPossible(vector<int>& position, int& force, int& m) {
        int count = 1;
        int start = position[0];
        for(int i = 0; i < position.size(); ++i) {
            if(position[i] - start >= force) {
                ++count;
                start = position[i];
            }
            if(count >= m) {
                return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
       sort(position.begin(), position.end());
       int l = 0;
       int r = position.back()-position.front();
       int ret = 0;
       while(l <= r) {
           int mid = l + (r-l)/2;
           if(isPossible(position, mid, m)) {
               ret = mid;
               l = mid + 1;
           } else {
               r = mid - 1;
           }
       }
       return ret;
    }
};
