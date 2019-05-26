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

Solution#2 Union-Find

class Solution {
public:
    
    string find(unordered_map<string, string>& parent, string email)
    {
        while(email != parent[email])
            email = parent[email];
        return email;
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> parents;
        unordered_map<string, string> owner;
        unordered_map<string, set<string>> unions;
        vector<vector<string>> ret;
        /* construct the parent relationship */
        for(int i = 0; i < accounts.size(); ++i)
        {
            for(int j = 1; j < accounts[i].size(); ++j)
            {
                string email = accounts[i][j];
                string person = accounts[i][0];
                parents[email] = email;
                owner[email] = person;
            }
        }
        
        /* connect the element who has the same parent */
        for(int i = 0; i < accounts.size(); ++i)
        {
            string p1 = find(parents, accounts[i][1]);
            for(int j = 2; j < accounts[i].size(); ++j)
            {
                string p2 = find(parents, accounts[i][j]);
                parents[p2] = p1;
            }
        }
        
        /* combine the email who has the same parent */
        /* set the union for the email address which has the same parent */
        for(int i = 0; i < accounts.size(); ++i)
        {
            for(int j = 1; j < accounts[i].size(); ++j)
            {
                string parent = find(parents, accounts[i][j]);
                unions[parent].insert(accounts[i][j]);
            }
        }
        
        for(auto e : unions)
        {
            vector<string> emails(e.second.begin(), e.second.end());
            emails.insert(emails.begin(), owner[e.first]);
            ret.push_back(emails);
        }
        return ret;
    }
};
