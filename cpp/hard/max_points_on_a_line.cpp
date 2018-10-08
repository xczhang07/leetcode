/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
     int maxPoints(vector<Point>& points) {
         int ret = 0;
         for(int i = 0; i < points.size(); ++i)
         {
             int duplicate = 1;
             map<pair<int, int>, int> m;
             for(int j = i + 1; j < points.size(); ++j)
             {
                 if(points[i].x == points[j].x && points[i].y == points[j].y)
                 {
                     ++duplicate;
                     continue;
                 }
                 int dx = points[i].x - points[j].x;
                 int dy = points[i].y - points[j].y;
                 int g = getGcd(dx, dy);
                 m[make_pair(dx/g, dy/g)]++;
             }
             ret = max(ret, duplicate);
             for(auto it = m.begin(); it != m.end(); it++)
                 ret = max(ret, it->second + duplicate);
         }
         return ret;
         
     }
    
    int getGcd(int num1, int num2)
    {
        if(num2)
            return getGcd(num2, num1%num2);
        else
            return num1;
    }

};


/*
a diffcult question on leetcode, for this question, we need to compute the gcd of the two numbers, time complexity is: O(n^2)

reference as following:
http://www.cnblogs.com/grandyang/p/4579693.html
https://leetcode.com/problems/max-points-on-a-line/discuss/47124/16ms28ms-C++-Solutions-with-Explanations
*/
