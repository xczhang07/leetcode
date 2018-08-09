class Solution {
public:
    string nextClosestTime(string time) {
        int map[10] = {0,0,0,0,0,0,0,0,0,0};
        char min = '9';
        for(char t: time)
        {
            if(t == ':')
                continue;
            map[t-'0']++;
            if(t < min) min = t;
        }
        /* 
        caculate the 4 digit one by one, we start caculate from minutes (most cloest to the current time)
        the time for the four digits range is: 
        1st: (0->2)
        2nd: if the 1st is 0, the second is in (1-9); if the 1st is 2, the second is in (0->3)
        3rd: (0->5)
        4th: (0->9)
        */
        for(int i = time[4]-'0'+1; i <= 9; ++i)
        {
            if(map[i] != 0)
            {
                time[4] = i+'0';
                return time;
            }
        }
        time[4] = min;
        for(int i = time[3]-'0'+1; i <= 5; ++i)
        {
            if(map[i] > 0)
            {
                time[3] = i+'0';
                return time;
            }
        }
        time[3] = min;
        int upper_bond = time[0] < '2' ? 9 : 3;
        for(int i = time[1]-'0'+1; i <= upper_bond; ++i)
        {
            if(map[i] > 0)
            {
                time[1] = i+'0';
                return time;
            }
        }
        time[1] = min;
        for(int i = time[0]-'0'+1; i <= 2; ++i)
        {
            if(map[i] > 0)
            {
                time[0] = i + '0';
                return time;
            }
        }
        time[0] = min;
        return time;
    }
};

Conclusion: a very straight farword solution for this algorithm issue, we caculate the time minute from the most right position of the 
input time because of modifying minute level is the closest to the current time.

