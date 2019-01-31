class Solution {
public:
    /**
     * @param arr: The 2-dimension array
     * @return: Return the column the leftmost one is located
     */
    int getColumn(vector<vector<int>> &arr) {
        // Write your code here
        if(arr.size() == 0 || arr[0].size() == 0)
            return 0;
        int m = arr[0].size()-1;
        int ret = m;
        for(int i = 0; i < arr.size(); ++i)
        {
            if(arr[i][m] != 0)
            {
                int c = binary_search(arr[i]);
                ret = min(ret, c);
                if(ret == 0)
                    return ret;
            }
        }
        
        return ret;
    }
    
    int binary_search(vector<int>& row)
    {
        int i = 0;
        int j = row.size()-1;
        while(i <= j)
        {
            int m = i + (j-i)/2;
            if(row[m] == 1)
            {
                if(m == 0 || (m > 0 && row[m-1] == 0))
                    return m;
                else
                    j = m-1;
            }
            else
                i = m+1;
        }
        return row[j] == 1 ? j : i;
    }
    
    
};

/*
Time Complexity is: O(m*logn)
m is the row number, n is the column number
*/
