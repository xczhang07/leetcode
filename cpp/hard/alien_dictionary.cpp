class Solution {
public:
     string alienOrder(vector<string>& words) {  
        if(words.size() == 0)
            return "";
         unordered_map<char, int> indegree; // caculate the indegree of each node
         unordered_map<char, multiset<char>> graph; //create the graph according to the input
         string ret;
         // initialize
         for(auto word : words)
         {
             for(auto c : word)
                 indegree[c] = 0;
         }
         // create the graph according to the input
         for(int i = 1; i < words.size(); ++i)
         {
             int k = 0;
             int len1 = words[i].size();
             int len2 = words[i-1].size();
             while(words[i-1][k] == words[i][k])
                 ++k;
             if(k >= min(len1, len2))
                 continue;
             indegree[words[i][k]]++;
             graph[words[i-1][k]].insert(words[i][k]);
         }
         // caculate the result
         for(int i = 0; i < indegree.size(); ++i)
         {
             char ch = ' ';
             for(auto val: indegree)
             {
                 if(!val.second) {
                     ch = val.first;
                     break;
                 }
             }
             if(ch == ' ')
                 return "";
             ret = ret + ch;
             indegree[ch]--;
             for(auto val: graph[ch])
                 indegree[val]--;
         }
         return ret;
    }  
};

Conclusion:
very diffcult question on leetcode, use topological sort to resolve the issue.

Time Complexity: O(N*M)
Space Complexity: O(N*M)

     
Solution# 2
class Solution {
public:
    string alienOrder(vector<string>& words) {
        string order;
        unordered_map<char, int> indegree;
        unordered_map<char, unordered_set<char>> graph;
        // initialize the indegree map.
        for(string& word: words) {
            for(int i = 0; i < word.size(); ++i) {
                indegree[word[i]] = 0;
            }
        }

        // build the graph based on the input words.
        for(int i = 1; i < words.size(); ++i) {
            int len = min(words[i].size(), words[i-1].size());
            int j = 0; 
            while(j < len) {
                if(words[i-1][j] != words[i][j]) {
                    if(!graph[words[i-1][j]].count(words[i][j])) {
                        indegree[words[i][j]]++;
                        graph[words[i-1][j]].insert(words[i][j]);
                    }
                    break;
                }
                ++j;
            }
            // if words[i] is prefix of words[i-1]; however, words[i] is short than words[i-1], then the input is not sorted.
            if(j == len && words[i-1].size() > words[i].size()) {
                return "";
            }
        }

        // topological-sort logic
        queue<char> q;
        // stores the element with 0 dependency.
        for(auto entry: indegree) {
            if(entry.second == 0) {
                q.push(entry.first);
            }
        }
        if(q.empty()) {
            return "";
        }

        while(!q.empty()) {
            char t = q.front();
            q.pop();
            order.push_back(t);
            for(char e: graph[t]) {
                indegree[e]--;
                if(indegree[e] == 0) {
                    q.push(e);
                }
            }
        }
        if(order.size() != indegree.size()) {
            return "";
        }
        return order;
    }
};
