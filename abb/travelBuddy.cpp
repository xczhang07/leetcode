1. buddy list
followup是给了一个max值，找出你的buddy的wishlist里不在你的wishlist里的最多max个城市，根据buddy和你的重合程度来排序
. From 1point 3acres bbs
例如 你的wishlist是 a,b,c,d
buddy1 的wishlist 是 a,b,e,f, 有两个和你的一样，所以是你的buddy
buddy2 的wishlist 是 a,c,d,g, 有三个和你的一样，也是你的budy

问题是输出一个size最多为max的推荐城市列表
当size为10时，buddy1和buddy2的wishlist中不在你的wishlist中的城市都可以加入推荐中，因为buddy2的重合度更高，所以先输出buddy2中的，所以推荐为 g,e,f
当size为2时，推荐是g,e 或 g,f

vector<string> travelBuddy(vector<string>& myCities, unordered_map<string, vector<string>>& friendsCities, int& k, vector<string>& kCities)
{
    if(myCities.size() == 0)
        return {};
    vector<string> ret;
    unordered_set<string> s(myCities.begin(), myCities.end());
    map<double, string> buddies;
    for(auto e : friendsCities)
    {
        int cnt = 0;
        for(string city: e.second)
        {
            if(s.count(city))
                cnt++;
        }
        double ratio = (double)cnt/e.second.size();
        if(ratio >= 0.5)
            buddies[ratio] = e.first;
    }
    
    /* get most k famous cities */
    for(auto iter = buddies.rbegin(); iter!=buddies.rend(); ++iter)
    {
        string buddy = iter->second;
        for(auto c: friendsCities[buddy])
        {
            if(!s.count(c))
            {
                if(kCities.size() < k)
                {
                    kCities.push_back(c);
                    if(kCities.size() == k)
                        break;
                }
            }
        }
    }
    
    for(auto e: buddies)
        ret.insert(ret.begin(), e.second);
    return ret;
}
