给一个数组表示一个巧克力棒每个方格的甜度，我要把巧克力棒-baidu 1point3acres
切成k份，让别人先挑选（挑选时选择当下嘴甜的一块），最后剩下的归我。
写一个函数计算我能得到的嘴甜的千克力块的甜度。

bool canSplit(vector<int>& candies, int& target, int& k, long& min_partition)
{
    long total = 0;
    int cnt = 0;
    for(int i = 0; i < candies.size(); ++i)
    {
        total += candies[i];
        if(total > target)
        {
            min_partition = min(min_partition, total-candies[i]);
            total = candies[i];
            cnt++;
            if(cnt > k)
                return false;
        }
    }
    
    min_partition = min(min_partition, total);
    return true;
}

int divideCandy(vector<int> candies, int k)
{
    if(candies.size() == 0)
        return 0;
    int min_value = INT_MAX;
    long sum = 0;
    long ret = 0;
    int n = candies.size();
    for(int i = 0; i < candies.size(); ++i)
    {
        min_value = min(min_value, candies[i]);
        sum += candies[i];
    }
    
    if(k == 1)
        return sum;
    if(k == n)
        return min_value;
    
    int target = 0;
    
    long l = min_value;
    long r = sum;
    k -= 1;
    while(l <= r)
    {
        target = l + (r-l)/2; /* avoid overflow */
        long min_partition = LONG_MAX;
        bool success = canSplit(candies, target, k, min_partition);
        if(success)
        {
            ret = max(ret, min_partition);
            r = target - 1;
        }
        else
            l = target + 1;
    }
    
    return ret;
}
