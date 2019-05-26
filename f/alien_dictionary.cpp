There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

Example 1:

Input:
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]

Output: "wertf"
Example 2:

Input:
[
  "z",
  "x"
]

Output: "zx"
Example 3:

Input:
[
  "z",
  "x",
  "z"
] 

Output: "" 

Explanation: The order is invalid, so return "".
Note:

You may assume all letters are in lowercase.
You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.



class Solution {
public:
    string alienOrder(vector<string>& words) {
        if(words.size() == 0)
            return "";
        /* we can use topological sort to resolve this issue. the steps as following:
        1. create an indegree array(the indegree array means the indegree number to each charactor)
        at the beginning, initialize each charactor's indegree is 0.
        eg: wrt in front of wrf => r order is head of f, and r->f, f indegree is 1
        2. create a graph data structure, which stores the sequence of for each charactor: eg
        input sorted list is: [wrt, wrf, er, ett, rftt]. 
        the graph should be: {
                              r: [f, t],
                              w: [e],
                              e: [r],
                              t: [f]
                              }
        3. after build the graph, we create a queue, the first step is insert all the charactor who's indegree is 0
        4. then we iterate the queue, pop the indegree 0 element and iterate its children , at the mean time minus 1
        for its children's indegree, if the indegree is 0, we push the element into the queue.
        5. after iterate the the queue, we compare the result string with the indegree array size, if they are not equal,
        which means there is circle exist in the input, return ""; otherwise return the ret string.
        */
        unordered_map<char, int> indegree;
        unordered_map<char, unordered_set<char>> g;
        queue<char> q;
        string order;
        
        /* step 1, construct the queue and initialize the indegree */
        for(int i = 0; i < words.size(); ++i)
        {
            for(int j = 0; j < words[i].size(); ++j)
                indegree[words[i][j]] = 0;
        }
        
        for(int i = 1; i < words.size(); ++i)
        {
            string word1 = words[i-1];
            string word2 = words[i];
            int j = 0;
            int len = min(word1.size(), word2.size());
            while(j < len)
            {
                if(word1[j] != word2[j])
                {
                    if(g[word1[j]].find(word2[j]) == g[word1[j]].end())
                    {
                        g[word1[j]].insert(word2[j]);
                        indegree[word2[j]]++;
                    }
                    break;
                }
                ++j;
            }
        }
        
        /* step 2, push all the charactor which indegree is 0 into the q */
        for(auto e : indegree)
        {
            if(e.second == 0)
                q.push(e.first);
        }
        
        if(q.size() == 0)
            return "";
        /* step 3, iterate the q with and build the order */
        while(!q.empty())
        {
            char t = q.front();
            q.pop();
            order.push_back(t);
            for(auto e : g[t])
            {
                --indegree[e];
                if(indegree[e] == 0)
                    q.push(e);
            }
        }
        
        /* step 4, validate whether or not the input order contains a circle */
        return order.size() != indegree.size() ? "": order;
    }
};

Time Complexity is: O(n + alphn)
Space Complexity is: O(n)
