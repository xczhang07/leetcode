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
        if(words.size() == 0)
            return "";
         unordered_map<char, int> indegree; // caculate the indegree of each node
         unordered_map<char, unordered_set<char>> graph; //create the graph according to the input
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
             int len = min(words[i].size(), words[i-1].size());
             for(int j = 0; j < len; ++j)
             {
                 if(words[i][j] != words[i-1][j])
                 {
                     if(graph[words[i-1][j]].find(words[i][j]) == graph[words[i-1][j]].end())
                     {
                        indegree[words[i][j]]++;
                        graph[words[i-1][j]].insert(words[i][j]);
                     }
                     break;
                 }
             }
         }
         // caculate the result
         queue<char> q;
         for(auto e : indegree)
         {
             if(e.second == 0)
                 q.push(e.first);
         }
         if(q.size() == 0)
             return "";
         
         while(!q.empty())
         {
             char t = q.front();
             q.pop();
             ret = ret + t;
             for(auto c : graph[t])
             {
                 indegree[c]--;
                 if(indegree[c] == 0)
                 {
                    q.push(c);
                 }
             }
         }
         if(ret.size() != indegree.size())
             return "";
         return ret;
    }  
};
