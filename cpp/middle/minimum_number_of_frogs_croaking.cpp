class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
       if(croakOfFrogs.size()%5 != 0) {
           return -1;
       }
       const string kCroak = "croak";
       vector<int> count(5,0);
       int frog_num = 0;
       int ret = 0;
       for(const char& c : croakOfFrogs) {
           ++count[kCroak.find(c)];
           for(int i = 1; i < 5; ++i) {
               if(count[i] > count[i-1]) {
                   return -1;
               }
           }
           if(c == 'c') {
               frog_num++;
           }
           if(c == 'k'){
               frog_num--;
           }
           ret = max(ret, frog_num);
       }
       return frog_num == 0? ret: -1;
    }
};
