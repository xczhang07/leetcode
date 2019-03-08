/*

Version#1: DFS version

*/

class Solution {
public:
    void dfs(set<string>& s, unordered_map<string, vector<int>>& g, vector<vector<string>>& accounts, vector<bool>& visited, int idx)
    {
        if(visited[idx])
            return;
        visited[idx] = true;
        for(int i = 1; i < accounts[idx].size(); ++i)
        {
            string email = accounts[idx][i];
            s.insert(email);
            for(auto user : g[email])
            {
                if(visited[user])
                    continue;
                dfs(s, g, accounts, visited, user);
            }
        }
        return;
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ret;
        if(accounts.size() == 0)
            return ret;
        /* build graph */
        unordered_map<string, vector<int>> g;
        for(int i = 0; i < accounts.size(); ++i)
        {
            for(int j = 1; j < accounts[i].size(); ++j)
                g[accounts[i][j]].push_back(i);
        }
        int n = accounts.size();
        vector<bool> visited(n, false);
        for(int i = 0; i < accounts.size(); ++i)
        {
            set<string> s;
            dfs(s, g, accounts, visited, i);
            vector<string> tmp(s.begin(), s.end());
            if(tmp.size() != 0)
            {
                tmp.insert(tmp.begin(), accounts[i][0]);
                ret.push_back(tmp);
            }
        }
        return ret;
    }
    
    
    
    
};
