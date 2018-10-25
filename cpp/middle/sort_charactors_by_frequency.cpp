class Solution {
public:
    string frequencySort(string s) {
        if(s.size() <= 1)
            return s;
        map<char,int> m;
        priority_queue<pair<int,char>> q;
        for(int i = 0; i < s.size(); ++i)
            m[s[i]]++;
        string ret;
        for(auto e : m)
            q.push(make_pair(e.second, e.first));
        while(!q.empty())
        {
            ret.append(q.top().first,q.top().second);
            q.pop();
        }
        return ret;
    }
};

/*
Time Complexity is: O(nlogn)
Space Complexity is: O(n)

*/
