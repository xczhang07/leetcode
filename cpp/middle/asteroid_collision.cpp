class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> res;
    for (auto a : asteroids) 
    {
        if (res.empty()) {
            res.push_back(a);
        } else {
            if (a > 0) {
                res.push_back(a);
            }
            else
            {
                if (res.back() < 0) {
                    res.push_back(a);
                }
                else
                {
                    while (!res.empty() && res.back()> 0 && res.back() < abs(a)) {
                        res.pop_back();
                    }
                    if(!res.empty())
                    {
                        if(res.back() < 0)
                            res.push_back(a);
                        else if(res.back() > 0 && res.back() == abs(a))
                            res.pop_back();
                    }
                    else
                        res.push_back(a);
                }
            }
        }
    }
    return res;
}
};

Time Complexity is: O(n)
Space Complexity is: O(n)
