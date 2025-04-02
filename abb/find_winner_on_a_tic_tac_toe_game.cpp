class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> row(3,0);
        vector<int> col(3,0);
        int i = 0;
        int diag = 0;
        int antiDiag = 0;
        for(auto m: moves) {
            int x = m[0];
            int y = m[1];
            // A moves 
            if(i%2 == 0) {
                row[x] += 1;
                col[y] += 1;
                if(x == y) {
                    diag += 1;
                }
                if(x == 2-y) {
                    antiDiag += 1;
                }
            } else { // B moves
                row[x] -= 1;
                col[y] -= 1;
                if(x == y) {
                    diag -= 1;
                }
                if(x == 2-y) {
                    antiDiag -= 1;
                }
            }
            i += 1;
            if(row[x] == 3 || col[y] == 3 || diag == 3 || antiDiag == 3) {
                return "A";
            }
            if(row[x] == -3 || col[y] == -3 || diag == -3 || antiDiag == -3) {
                return "B";
            }
        }
        if(moves.size() < 9) {
            return "Pending";
        }
        return "Draw";
    } 
};
