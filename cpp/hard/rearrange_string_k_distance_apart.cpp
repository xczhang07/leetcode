class Solution {
public:
    string rearrangeString(string s, int k) {
        if(k == 0)
            return s;
        unordered_map<char, int> freq;
        priority_queue<pair<int,char>> pq;
        /* caculate the frequency of the charactors in string */
        for(char c : s)
            freq[c]++;
        /* construct the priority queue */
        for(auto f : freq)
            pq.push(make_pair(f.second, f.first));
        
        string ret;
        while(!pq.empty())
        {
            vector<pair<int,char>> buff;
            int i = 0;
            while(i < k && !pq.empty())
            {
                auto p = pq.top();
                pq.pop();
                ret.push_back(p.second);
                p.first--;
                if(p.first)
                    buff.push_back(p);
                ++i;
            }
            
            if(i != k && buff.size() != 0)
                return "";
            for(auto t: buff)
                pq.push(t);
        }
        return ret;
    }
};
