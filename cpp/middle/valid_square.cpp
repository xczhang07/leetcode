class Solution {
public:
    int calculateDistance(vector<int>& p1, vector<int>& p2)
    {
        int d = (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]);
        return d;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> s;
        s.insert(calculateDistance(p1,p2));
        s.insert(calculateDistance(p1,p3));
        s.insert(calculateDistance(p1,p4));
        s.insert(calculateDistance(p2,p3));
        s.insert(calculateDistance(p2,p4));
        s.insert(calculateDistance(p3,p4));
        
        if(s.count(0))
            return false;
        if(s.size() == 2)
            return true;
        return false;
    }
};
