算法。题目是给定两个字符串a和b，对a进行多次复制并且删除某一些character，能不能把它变成b，返回boolean。比如a = abdc, b = baccd, 
对a复制三次并删去一些字符可以变成b。follow up是最少复制次数是多少。

bool makeup(string s1, string s2, int& times)
{
    if(s1.size() == 0)
        return false;
    unordered_set<char> s;
    for(int i = 0; i < s1.size(); ++i)
        s.insert(s1[i]);
    for(int i = 0; i < s2.size(); ++i)
    {
        if(!s.count(s2[i]))
            return false;
    }
    
    int j = 0;
    while(j < s2.size())
    {
        int k = 0;
        while(k < s1.size())
        {
            if(s2[j] == s1[k])
                ++j;
            ++k;
        }
        ++times;
    }
    return true;
}
