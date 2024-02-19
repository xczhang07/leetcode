class Solution {
public:
    string reorganizeString(string s) {
       if(s.size() == 0) {
           return "";
       }
       unordered_map<char, int> freq_m;
       for(char e: s) {
           freq_m[e]++;
       }
       priority_queue<pair<int, char>> pq;
       for(auto entry: freq_m) {
           pq.push({entry.second, entry.first});
       }
       string ret;
       while(pq.size() >= 2) {
           auto p1 = pq.top();
           pq.pop();
           auto p2 = pq.top();
           pq.pop();
           ret = ret + p1.second + p2.second;
           if(p1.first-1 > 0) {
               pq.push({p1.first-1, p1.second});
           }
           if(p2.first-1 > 0) {
               pq.push({p2.first-1, p2.second});
           }
       }
       if(pq.size() > 0) {
           if(pq.top().first > 1) {
               return "";
           }
           ret += pq.top().second;
       }
       return ret;
    }
};
