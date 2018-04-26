class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size() != B.size())
            return false;
        if(A == B)
            return true;
        for(int i = 0; i < B.size(); ++i)
        {
            if(i < B.size()-1)
            {
                string sub_str1 = B.substr(0,i+1);
                string sub_str2 = B.substr(i+1);
                if(A.find(sub_str1) != -1 && A.find(sub_str2) != -1)
                    return true;
            }
        }
        return false;
    }
};

/* this function is used to test whether or not str2 is a sub-string of str1 
   if str2 is a substring of str1, return true, if not, return false
*/
bool is_substring(string& str1, string& str2)
{
	if(str1.find(str2) == -1)
		return false;
	else
		return true;
}

Conclusion:
an easy algorithm issue. No comment

Time Complexity: O(n)
Space Complexity: O(1)
