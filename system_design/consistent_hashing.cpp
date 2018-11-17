class Solution {
public:
    /*
     * @param n: a positive integer
     * @return: n x 3 matrix
     */
    vector<vector<int>> consistentHashing(int n) {
        // write your code here
        vector<vector<int>> ret;
        ret.push_back({0,359,1});
        for(int i = 1; i < n; ++i)
        {
            int max_idx = 0;
            for(int j = 1; j < i; ++j)
            {
                int m = ret[j][1]-ret[j][0]+1;
                int n = ret[max_idx][1]-ret[max_idx][0]+1;
                if(m > n) max_idx = j;
            }
            
            int x = ret[max_idx][0];
            int y = ret[max_idx][1];
            ret[max_idx][1] = (x+y)/2;
            vector<int> new_machine(3,0);
            new_machine[0] = (x+y)/2+1;
            new_machine[1] = y;
            new_machine[2] = i+1;
            ret.push_back(new_machine);
        }
        return ret;
    }
   
};
