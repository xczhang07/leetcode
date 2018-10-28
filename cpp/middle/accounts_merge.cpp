class Solution {
public:
    string find(string email, map<string, string>& parents)
    {
        while(email != parents[email])
            email = parents[email];
        return email;
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        /* a typical union-find algorithm issue */
        map<string, string> owner;
        map<string, string> parents;
        map<string, set<string>> unions; /* we use set because of set is ordered */
        vector<vector<string>> ret;
        /* do the initialization for parents and owners */
        for(int i = 0; i < accounts.size(); ++i)
        {
            for(int j = 1; j < accounts[i].size(); ++j)
            {
                parents[accounts[i][j]] = accounts[i][j];
                owner[accounts[i][j]] = accounts[i][0];
            }
        }
        
        /* find the parents for each email address */
        for(int i = 0; i < accounts.size(); ++i)
        {
            string p = find(accounts[i][1], parents);
            for(int j = 2; j < accounts[i].size(); ++j)
            {
                string sub_p = find(accounts[i][j], parents);
                parents[sub_p] = p;
            }
        }
        
        /* set the union for the email address which has the same parent */
        for(int i = 0; i < accounts.size(); ++i)
        {
            for(int j = 1; j < accounts[i].size(); ++j)
            {
                string parent = find(accounts[i][j], parents);
                unions[parent].insert(accounts[i][j]);
            }
        }
        
        /* combine the results for all the users */
        for(auto e : unions)
        {
            vector<string> emails(e.second.begin(), e.second.end());
            emails.insert(emails.begin(), owner[e.first]);
            ret.push_back(emails);
        }
        return ret;
    }
};

/*
a middle level algorithm issue, using union-find to resolve this issue.
*/
