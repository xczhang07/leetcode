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
Space Complexity is: O(1)

*/

Solution# 2:
bucket sort version solution

Time Complexity is: O(n)
Space Complexity is: O(n)

class Solution {
public:
    string frequencySort(string s) {
        if(s.size() <= 1)
            return s;
        vector<string> bucket(s.size()+1, "");
        unordered_map<char, int> freq;
        string ret;
        for(int i = 0; i < s.size(); ++i)
            freq[s[i]]++;
        for(auto f : freq)
        {
            int idx = f.second;
            int val = f.first;
            bucket[idx].append(idx, val);
        }
        
        for(int i = bucket.size()-1; i >= 0; --i)
        {
            if(bucket[i].size() != 0)
                ret += bucket[i];
        }
        return ret;
    }
};
