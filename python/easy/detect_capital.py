class Solution(object):
    def detectCapitalUse(self, word):
        """
        :type word: str
        :rtype: bool
        """
        template = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        cap_cnt = 0
        pos = 0
        idx = 0
        for idx in range(0, len(word)):
            if word[idx] in template:
                cap_cnt += 1
                pos = idx
        if cap_cnt == len(word):
            return True
        elif cap_cnt == 1 and pos == 0:
            return True
        elif cap_cnt == 0:
            return True
        else:
            return False
