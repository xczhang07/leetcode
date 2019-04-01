long findMedianHelper(vector<int>& nums, int k, long left, long right)
{
    if(left >= right)
        return left;
    long ret = left;
    long guess = (left + right)/2;
    int count = 0;
    for(int num : nums)
    {
        if(num <= guess)
        {
            ++count;
            ret = max(ret, guess);
        }
    }
    
    if(k == count)
        return ret;
    else if(count < k)
        return findMedianHelper(nums, k, max(ret+1, guess), right);
    else
        return findMedianHelper(nums, k, left, ret);
}

double findMedian(vector<int>& nums)
{
    int len = nums.size();
    if(len % 2 == 1)
        return (double)findMedianHelper(nums, len/2+1, LONG_MIN, LONG_MAX);
    else
        return (double)(findMedianHelper(nums, len/2, LONG_MIN, LONG_MAX)+findMedianHelper(nums, len/2+1, LONG_MIN, LONG_MAX))/2;
}
