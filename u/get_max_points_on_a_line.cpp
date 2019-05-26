/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 
 
 Time Complexity is: O(n^2)
 Space Complexity is: O(n^2)
 
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int ret = 0;
        int dup = 1;
        if(points.size() == 0)
            return ret;
        for(int i = 0; i < points.size(); ++i)
        {
            map<pair<int,int>, int> m;
            dup = 1;
            for(int j = i+1; j < points.size(); ++j)
            {
                Point p1 = points[i];
                Point p2 = points[j];
                if(p1.x == p2.x && p1.y == p2.y)
                    dup++;
                else
                {
                    int d1 = p1.x-p2.x;
                    int d2 = p1.y-p2.y;
                    int gcd = getGCD(d1, d2);
                    m[make_pair(d1/gcd, d2/gcd)]++;
                }
            }
            ret = max(ret, dup);
            for(auto e : m)
                ret = max(ret, e.second+dup);
        }
        
        return ret;
    }
    
    int getGCD(int num1, int num2)
    {
        if(num2 == 0)
            return num1;
        else
            return getGCD(num2, num1%num2);
    }
};
