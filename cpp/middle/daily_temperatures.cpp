class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ret(temperatures.size());
        stack<int> st;
        int n = temperatures.size();
        for(int i = 0; i < n; ++i)
        {
            int j = i;
            while(!st.empty() && temperatures[st.top()] < temperatures[j])
            {
                ret[st.top()] = j - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ret;
    }
};

Conclusion:
middle algorithm issue, using stack to resolve the issue.


