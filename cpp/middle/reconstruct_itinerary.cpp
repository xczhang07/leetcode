class Compare {
    public:
    bool compareString(string& s1, string& s2)
    {
        return s1 < s2;
    }
};

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> ret;
        if(tickets.size() == 0)
            return ret;
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> my_map;
        // construct the graph
        for(auto e: tickets)
            my_map[e.first].push(e.second);
        dfs("JFK", ret, my_map);
        reverse(ret.begin(), ret.end()); // need to reverse the result string.
        return ret;
    }
    
    void dfs(string airport, vector<string>& ret, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& m)
    {
        /*from buttom up*/
        while(!m[airport].empty())
        {
            string next_city = m[airport].top();
            m[airport].pop(); /* once visit a city, we need to remove that city from queue */
            dfs(next_city, ret, m);
        }
        ret.push_back(airport);
        return;
    }
};


/*
Conclusion:
a middle level question on leetcode, graph category, 
1. construct the graph according to the input edge
2. start to dfs travel from "JFK" airport
3. in the dfs function, use "bottom up" strategy to resolve the issue 
4. reverse the result array.

Time Complexity: O(V*E)
Space Complexity: O(V)
*/
