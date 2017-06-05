class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if len(grid) == 0:
            return 0
        l = len(grid)
        h = len(grid[0])
        perimeter = 0
        for x in range(l):
            for y in range(h):
                if grid[x][y] == 0:
                    continue
                if x == 0 or grid[x-1][y] == 0:
                    perimeter += 1
                if x == l-1 or grid[x+1][y] == 0:
                    perimeter += 1
                if y == 0 or grid[x][y-1] == 0:
                    perimeter += 1
                if y == h-1 or grid[x][y+1] == 0:
                    perimeter += 1
        return perimeter
