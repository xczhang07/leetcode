class Solution {
public:
    bool isFriend(int x, int y) {
        bool cond1 = (y <= 0.5*x + 7);
        bool cond2 = (y > x);
        bool cond3 = (y > 100 && x < 100);
        return !(cond1||cond2||cond3);
    }

    int numFriendRequests(vector<int>& ages) {
        unordered_map<int, int> ageToNum;
        int ret = 0;
        for(int& age: ages) {
            ageToNum[age] += 1;
        }

        for(auto p1: ageToNum) {
            for(auto p2: ageToNum) {
                if(isFriend(p1.first, p2.first)) {
                    if(p1.first == p2.first) {
                        ret += p1.second * (p1.second-1); // exclude the people self.
                    } else {
                        ret += p1.second * p2.second;
                    }
                }
            }
        }
        return ret;
    }
};
