class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ret = []
        ret.append([])
        if len(nums) == 0:
            return ret
        tmp = []
        idx = 0
        
        def dfs(nums, idx):
            if idx >= len(nums):
                return
            for i in range(idx, len(nums)):
                tmp.append(nums[i])
                test = tmp[:]
                ret.append(test)
                dfs(nums, i+1)
                tmp.pop()
            return
        
        dfs(nums, idx)
        return ret
        
