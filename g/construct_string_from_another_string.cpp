第一轮：给两个字母串 str1 = “ABABZ”, str2 = "ABZ", 判断str1能否用str2中的字符拼成，
如果能，最少的步数是多少？例子，从str2中取“A”，“B”，“A”，“B”，“Z”一共五步，但如果取“AB”，“ABZ”只需要两步。
follow up，如果str2中有duplicate，BFS shortest path问题

第一个题的解释，换一种说法，就是从str2里每次可以取出一个substring，需要取多少次才能拼成str1.在没有duplicate的情况下，直接比较下一个字符串是否相同。

先要判断能不能成。如果str1里有字符不在str2，就不能成。 能成的情况下最多len(strt1)肯定可以嘛，所以要求的是最少需要几次。


void calculateSteps(string str1, string& str2, int idx, int& steps, int tmp)
{
    if(idx >= str1.size())
    {
        steps = min(steps, tmp);
        return;
    }
    for(int i = 1; i <= str1.size(); ++i)
    {
        string curr = str1.substr(0,i);
        string next = str1.substr(i);
        if(str2.find(curr) != string::npos && tmp+1 < steps)
        {
            calculateSteps(next, str2, idx, steps, tmp+1);
        }
    }
}


int minStepsToConstructString(string str1, string str2)
{
    unordered_set<char> s;
    for(int i = 0; i < str2.size(); ++i)
        s.insert(str2[i]);
    for(int i = 0; i < str1.size(); ++i)
    {
        if(!s.count(str1[i]))
            return -1;
    }
    int min_steps = INT_MAX;
    int idx = 0;
    int tmp = 0;
    calculateSteps(str1, str2, idx, min_steps, tmp);
    return min_steps;
}
