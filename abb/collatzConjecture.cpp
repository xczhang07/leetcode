一面感觉是亚裔二代，比较友善。
题目是给你公式，比如偶数的话除2，奇数的话就变成3*n+1，对于任何一个正数，数学猜想是最终他会变成1。每变一步步数加1，给一个上限，让找出范围内最长步数。

int collatzConjecture(int num, unordered_map<int,int>& m)
{
    if(num == 1)
        return 1;
    if(m.count(num))
        return m[num];
    if(num % 2 == 0)
        return collatzConjecture(num/2, m)+1;
    else
        return collatzConjecture(3*num+1, m)+1;
}

int findSteps(int num)
{
    int ret = 0;
    unordered_map<int,int> m;
    for(int i = 1; i <= num; ++i)
    {
        int steps = collatzConjecture(num, m);
        m[i] = steps;
        ret = max(ret, steps);
    }
    return ret;
}
