class NumArray(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.num_sum = [0]
        for num in nums:
            self.num_sum.append(self.num_sum[-1] + num)

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.num_sum[j+1] - self.num_sum[i]
        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
