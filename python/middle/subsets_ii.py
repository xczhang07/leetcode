class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ret = [[]]
        if len(nums) == 0:
            return ret
        idx = 0
        tmp = []
        nums.sort()
        
        def dfs(index):
            if index >= len(nums):
                return
            for i in range(index, len(nums)):
                tmp.append(nums[i])
                if tmp not in ret:
                    test = tmp[:]
                    ret.append(test)
                dfs(i+1)
                tmp.pop()
                while( (i < len(nums)-1) and (nums[i] == nums[i+1])):
                    i += 1
            return
        dfs(idx)
        return ret
