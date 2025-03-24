class Solution {
public:
    bool isRobotBounded(string instructions) {
        if(instructions.size() == 0) {
            return true;
        }
        char direction = 'N';
        int x = 0, y = 0; // start position coordinates.
        for(int i = 0; i < instructions.size(); ++i) {
            // move once receive instruction 'G'.
            if(instructions[i] == 'G') {
                if(direction == 'N') {
                    y += 1;
                } else if(direction == 'S') {
                    y -= 1;
                } else if(direction == 'E') {
                    x += 1;
                } else {
                    x -= 1;
                }
            } else {
                if(instructions[i] == 'L') {
                    if(direction == 'N') {
                        direction = 'W';
                    } else if(direction == 'S') {
                        direction = 'E';
                    } else if(direction == 'E') {
                        direction = 'N';
                    } else {
                        direction = 'S';
                    }
                } else {
                    if(direction == 'N') {
                        direction = 'E';
                    } else if(direction == 'S') {
                        direction = 'W';
                    } else if(direction == 'E') {
                        direction = 'S';
                    } else {
                        direction = 'N';
                    }
                }
            }
        }
        if((x == 0 and y == 0) or direction != 'N') {
            return true;
        } 
        return false;
    }
};
