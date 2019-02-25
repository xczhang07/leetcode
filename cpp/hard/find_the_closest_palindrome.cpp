class Solution {
public:
     string nearestPalindromic(string n) {
         long l = n.size();
         long num = stol(n);
         long ret;
         unordered_set<long> s;
         long diff = LONG_MAX;
         
         long pre = stol(n.substr(0, (l+1)/2));
         
         s.insert(pow(10, l)+1);
         s.insert(pow(10, l-1)-1);
         
         for(int i = -1; i <= 1; ++i)
         {
             string left = to_string(pre+i);
             string str;
             string right;
             if(l%2 == 0)
                 right = left;
             else
                 right = left.substr(0, left.size()-1);
             reverse(right.begin(), right.end());
             str = left + right;
             s.insert(stol(str));
         }
         
         s.erase(num);
         for(auto e: s)
         {
             long tmp = abs(e-num);
             if(tmp < diff)
             {
                 diff = tmp;
                 ret = e;
             }
             else if(tmp == diff)
                 ret = min(ret, e);   
         }
         return to_string(ret);
    }
};
