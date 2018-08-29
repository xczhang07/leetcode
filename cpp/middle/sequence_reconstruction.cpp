class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
       if(seqs.size() == 0)
           return false;
        int n = org.size();
        int cnt = n - 1;
        vector<int> pos(n+1, 0);
        vector<bool> flag(n+1, false);
        bool is_exist = false;
        /* record the position of the element in org */
        for(int i = 0; i < org.size(); ++i)
        {
            pos[org[i]] = i;
        }
        for(auto seq : seqs)
        {
            for(int i = 0; i < seq.size(); ++i)
            {
                is_exist = true;
                if(seq[i] <= 0 || seq[i] > n)
                    return false;
                if(i == 0)
                    continue;
                int pre = seq[i-1];
                int cur = seq[i];
                if(pos[pre] >= pos[cur])
                    return false;
                if(flag[cur] == false && pos[pre]+1 == pos[cur])
                {
                    flag[cur] = true;
                    cnt--;
                }
            }
        }
        return cnt == 0 && is_exist;
    }
};


Conclusion: an middle level algorithm issue, not easy, we can use topological sort to resolve the issue and we can also use the logical method to resolve the issue.

Time Complexity: O(n*m)

Space Complexity: O(n)
