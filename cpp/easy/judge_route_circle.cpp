class Solution {
public:
    bool judgeCircle(string moves) {
        int vertical = 0;
        int horizional = 0;
        for(int i = 0; i < moves.size(); ++i)
        {
            if(moves[i] == 'L')
                horizional--;
            else if(moves[i] == 'R')
                horizional++;
            else if(moves[i] == 'D')
                vertical--;
            else
                vertical++;
        }
        if(vertical == 0 && horizional == 0)
            return true;
        else
            return false;
    }
};


we define two variables: one is used to create vertical move (down and up), another is used to create horizional move (left and right).
after iterate the whole string, if both of the two direction variables is 0, then the robot come back to the circle; otherwise, it means the
robot does not perform a circle move.

Time Complexity: O(n)
Space Complexity: O(1)
