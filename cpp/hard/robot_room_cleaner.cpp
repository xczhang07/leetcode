/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
    vector<pair<int,int>> dirs = {{0,-1}, {1, 0}, {0, 1}, {-1, 0}};
    
    void cleanRoom(Robot& robot) 
    {
        set<pair<int,int>> s;
        helper(robot, 0, 0, 0, s);
        return;
    }
    
    
    void helper(Robot& robot, int x, int y, int d, set<pair<int,int>>& s)
    {
        robot.clean();
        s.insert(make_pair(x, y));
        for(int i = 0; i < dirs.size(); ++i)
        {
            int curr = (i+d)%4;
            int nx = dirs[curr].first + x;
            int ny = dirs[curr].second + y;
            if(!s.count(make_pair(nx, ny)) && robot.move())
            {
                helper(robot, nx, ny, curr, s);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnLeft();
                robot.turnLeft();
            }
            robot.turnRight();
        }
        return;
    }
    
};
