Given a set of 2-D points, find four points, which can become a rectangle, parallel to X or Y axis. 
   Brute force way is to do nested loop to find out four points.

https://www.quora.com/From-a-given-set-of-points-how-would-you-find-the-set-of-4-points-forming-a-rectangle

time complexity is: O(m*n*l)
space complexity is: O(m*n)

vector<int> getIntersection(vector<int> l1, vector<int> l2)
{
    vector<int> ret;
    unordered_map<int, int> m;
    for(int i = 0; i < l1.size(); ++i)
        m[l1[i]]++;
    for(int j = 0; j < l2.size(); ++j)
    {
        if(m.count(l2[j]))
        {
            ret.push_back(l2[j]);
            if(ret.size() >= 2)
                break;
        }
    }
    return ret;
}


vector<pair<int,int>> findRectangles(vector<pair<int,int>> points)
{
    vector<pair<int,int>> rectangle;
    if(points.size() < 4)
        return rectangle;
    unordered_map<int, vector<int>> m;
    for(auto p : points)
        m[p.first].push_back(p.second);
    auto iter1 = m.begin();
    for(iter1; iter1 != m.end(); ++iter1)
    {
        auto iter2 = next(iter1, 1);
        while(iter2 != m.end())
        {
            vector<int> l1 = iter1->second;
            vector<int> l2 = iter2->second;
            vector<int> ret = getIntersection(l1, l2);
            if(ret.size() == 2)
            {
                rectangle = {make_pair(iter1->first, ret[0]), make_pair(iter1->first, ret[1]),
                    make_pair(iter2->first, ret[0]), make_pair(iter2->first, ret[1])
                };
                return rectangle;
            }
            iter2++;
        }
    }
    return rectangle;
}
