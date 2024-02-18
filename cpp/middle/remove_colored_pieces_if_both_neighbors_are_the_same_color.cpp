class Solution {
public:
    bool winnerOfGame(string colors) {
        int aliceMove = 0;
        int bobMove = 0;
        for(int i = 1; i < colors.size()-1; ++i) {
            if(colors[i-1] == 'A' && colors[i] == 'A' && colors[i+1] == 'A') {
                aliceMove++;
            } else if(colors[i-1] == 'B' && colors[i] == 'B' && colors[i+1] == 'B') {
                bobMove++;
            }
        }
        return aliceMove > bobMove;
    }
};
