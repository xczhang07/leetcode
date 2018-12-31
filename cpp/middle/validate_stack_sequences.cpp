class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() != popped.size())
            return false;
        stack<int> st;
        int i = 0;
        int j = 0;
        while(i < pushed.size() && j < popped.size())
        {
            if(pushed[i] != popped[j])
            {
                st.push(pushed[i]);
                ++i;
            }
            else
            {
                ++i;
                ++j;
                while(j < popped.size() && (!st.empty() && st.top() == popped[j]))
                {
                    st.pop();
                    ++j;
                }
                
            }
        }
        
        return st.empty();
    }
};
