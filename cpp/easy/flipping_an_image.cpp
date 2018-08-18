class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if(A.size() == 0 || A[0].size() == 0)
            return A;
        /* flip the each raw */
        for(int i = 0; i < A.size(); ++i)
            reverse_array(A[i]);
        /* invert each row */
        for(int i = 0; i < A.size(); ++i)
        {
            for(int j = 0; j < A[i].size(); ++j)
            {
                if(A[i][j]==1)
                    A[i][j] = 0;
                else
                    A[i][j] = 1;
            }
        }
        return A;
    }
    
    void reverse_array(vector<int>& arr)
    {
        int i = 0; 
        int j = arr.size()-1;
        while(i < j)
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            ++i;
            --j;
        }
        return;
    }
};


Conclusion:
an easy algorithm issue, no comments on the issue, very easy.
Time Complexity: O(m*n)
Space Complexity: O(1)
