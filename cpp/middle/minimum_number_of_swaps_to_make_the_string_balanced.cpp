class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int counter = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '[') {
                st.push(s[i]);
            } else {
                if(!st.empty()) {
                    st.pop();
                } else {
                    counter += 1;
                }
            }
        }
        return counter/2 + counter%2;
    }
};
