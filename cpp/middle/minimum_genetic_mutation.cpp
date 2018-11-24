class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        /* classic BFS issue, same as word ladder */
        if(start.size() != end.size())
            return -1;
        if(start.size() == 0)
            return -1;
        unordered_set<string> genicSet(bank.begin(), bank.end());
        vector<char> choice = {'A', 'C', 'G', 'T'};
        int step = 0;
        queue<string> q;
        q.push(start);
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0; i < n; ++i)
            {
                string genic = q.front();
                if(genic == end)
                    return step;
                q.pop();
                for(int j = 0; j < genic.size(); ++j)
                {
                    string tmp = genic;
                    for(int k = 0; k < choice.size(); ++k)
                    {
                        char c = tmp[j];
                        if(c == choice[k])
                            continue;
                        tmp[j] = choice[k];
                        if(genicSet.find(tmp) != genicSet.end())
                        {
                            q.push(tmp);
                            genicSet.erase(tmp);
                        }
                        tmp[j] = c;
                    }
                }
            }
            ++step;
        }
        return -1;
    }
};

/*
Time Complexity is: O(m*n)
Space Complexity is: O(m*n)
*/
