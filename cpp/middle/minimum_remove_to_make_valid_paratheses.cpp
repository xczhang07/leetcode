class Solution {
public:
    string minRemoveToMakeValid(string s) {
        if(s.size() == 0) {
            return s;
        }
        stack<pair<char, int>> idx_st;
        set<int> idx_set;
        string ret;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(' || s[i] == ')') {
                if(idx_st.empty()) {
                    idx_st.push({s[i], i});
                } else if (idx_st.top().first == '(' && s[i] == ')') {
                    idx_st.pop();
                } else {
                    idx_st.push({s[i], i});
                }
            }
        }
        while(!idx_st.empty()) {
            idx_set.insert(idx_st.top().second);
            idx_st.pop();
        }
        for(int i = 0; i < s.size(); ++i) {
            if(idx_set.find(i) == idx_set.end()) {
                ret += s[i];
            }
        }
        return ret;
    }
};
