Solution#1 
reference: http://www.cnblogs.com/grandyang/p/5595614.html

Time Complexity is: O(n)
Space Complexity is: O(n)

class Solution {
public:
    
    int caculate(int x, int& a, int& b, int& c)
    {
        return a*x*x + b*x + c;
    }
    
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> ret(n, 0);
        int i = 0;
        int j = n-1;
        int t = (a >= 0)?n-1:0;
        while(i <= j)
        {
            int num1 = caculate(nums[i], a, b, c);
            int num2 = caculate(nums[j], a, b, c);
            if(a < 0)
            {
                if(num1 < num2)
                {
                    ret[t++] = num1;
                    ++i;
                }
                else
                {
                    ret[t++] = num2;
                    --j;
                }
            }
            else
            {
                if(num1 < num2)
                {
                    ret[t--] = num2;
                    --j;
                }
                else
                {
                    ret[t--] = num1;
                    ++i;
                }
            }
        }
        return ret;
    }
};


Solution#2 pq + math
Time Complexity is: O(nlogn)
Space Complexity is: O(n)

class Solution {
public:
    
    int caculate(int x, int& a, int& b, int& c)
    {
        return a*x*x + b*x + c;
    }
    
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i)
        {
            int ret = caculate(nums[i], a, b, c);
            pq.push(ret);
        }
        while(!pq.empty())
        {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
    
    
};
