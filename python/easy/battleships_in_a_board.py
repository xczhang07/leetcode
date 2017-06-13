class Solution(object):
    def countBattleships(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        if len(board) == 0:
            return 0
        ret = 0
        for i in xrange(0, len(board)):
            for j in xrange(0, len(board[i])):
                if board[i][j] == 'X':
                    if (i == 0 or board[i-1][j] == '.') and (j == 0 or board[i][j-1] == '.'):
                        ret += 1
        return ret
