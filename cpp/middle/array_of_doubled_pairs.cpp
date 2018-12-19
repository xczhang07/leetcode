class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        if(A.size() == 0) return true;
        if(A.size()%2 == 1) return false;
        sort(A.begin(), A.end());
        map<int, int> m;
        for(int num : A)
            m[num]++;
        for(int num : A)
        {
            if(m.find(num) == m.end())
                continue;
            if(m.find(2*num) != m.end())
            {
                m[num]--;
                m[2*num]--;
                if(m[num] == 0)
                    m.erase(num);
                if(m[2*num] == 0)
                    m.erase(2*num);
            }
        }
        return m.size() == 0;
    }
};
