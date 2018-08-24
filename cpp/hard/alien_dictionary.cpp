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
