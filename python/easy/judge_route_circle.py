class Solution(object):
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        return moves.count('R') == moves.count('L') and moves.count('U') == moves.count('D')
        
        
        
One line python code solution
