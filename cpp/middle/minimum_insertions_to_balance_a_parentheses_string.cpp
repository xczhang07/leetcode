class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int leftCnt = 0;
        int ret = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] == '(') {
                leftCnt++;
            } else {
                if(i == n-1 || s[i+1] != ')') {
                    ret += 1;
                } else {
                    ++i;
                }
                // Now we guarrente two right parentheses
                if(leftCnt == 0) {
                    ret += 1;
                } else {
                    leftCnt -= 1;
                }
            }
        }
        return ret + leftCnt*2;
    }
};
