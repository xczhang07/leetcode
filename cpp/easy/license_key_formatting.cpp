class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        /* process the input string from reverse order. to avoid the first group
        could be less than K charactors requirements, smart solution */
       string result="";
        int count=0;
        for(int i=S.length()-1;i>=0;i--){   
            if(count==K && S[i] != '-'){  // add S[i] != '-' constraints to avoid the first charactor is "-" case. N "-" group the input string to N+1 groups
                result= '-'+ result;
                count=0;
            }
            if(S[i]!='-'){
                 result=(char)toupper(S[i])+result;
                 count++;
            }               
        }
        return result;
    }
};

Conclusion:

tagged as an easy algorithm issue, IMO, this issue is not a easy one, in order to avoid the first group charactors 
issue, we can process the input string from the end to start. the second issue we need to notice is that we should take
care of the first charactor is '-' case for the input string

Time Complexity: O(n)
Space Complexity: O(1)


