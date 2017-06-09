class Solution(object):
    def findRestaurant(self, list1, list2):
        """
        :type list1: List[str]
        :type list2: List[str]
        :rtype: List[str]
        """
        d1 = dict()
        least_idx_sum = sys.maxint
        idx = 0
        ret = list()
        for idx in range(0, len(list2)):
            d1[list2[idx]] = idx
        idx = 0
        for idx in range(0, len(list1)):
            if list1[idx] in d1:
                sum = idx + d1[list1[idx]]
                if sum == least_idx_sum:
                    ret.append(list1[idx])
                elif sum < least_idx_sum:
                    least_idx_sum = sum
                    ret= []
                    ret.append(list1[idx])
        return ret
