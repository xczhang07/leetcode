//
//  connectN.h
//  AirbnbCodingChallenge
//
//  Created by Xiaochong Zhang on 4/24/25.
//
// https://www.1point3acres.com/bbs/thread-1127709-1-1.html

#ifndef connectN_h
#define connectN_h

#include <iostream>
#include <vector>

using namespace std;

// connectN
class connectN {
public:
    connectN(int row, int col, int n) {
        initGameBoard(row, col);
        this->rowNum = row;
        this->colNum = col;
        this->n = n;
    }
    
    int move(int column, int playerId){
        if(column < 0 || column >= this->colNum) {
            cout<<"place column value is invalid: "<<column<<endl;
            throw "invalid column input";
        }
        if(playerId != 1 and playerId != 2) {
            cout<<"invalid player id: "<<playerId<<endl;
            throw "invalid player input";
        }
        int r = this->rowNum-1;
        bool placeSuccess = false;
        for(; r >= 0; --r) {
            if(gameBoard[r][column] == 0) {
                gameBoard[r][column] = playerId;
                placeSuccess = true;
                break;
            }
        }
        if(!placeSuccess) {
            cout<<"No space to move, choose another column"<<endl;
            return -1;
        }
        // if move success, we check the whether or not the player win the game.
        // currently, the position is [r, column].
        if(checkWin(r, column, playerId)) {
            cout<<"player "<<playerId<<" wins the game. Big congrats"<<endl;
            printWinBoard();
            return 1;
        }
        // no one wins yet.
        return 0;
    }
    
    
private:
    void printWinBoard() {
        cout<<"Winner Game Board"<<endl;
        for(int r = 0; r < this->rowNum; ++r) {
            for(int c = 0; c < this->colNum; ++c) {
                if(this->gameBoard[r][c] == 1) {
                    cout<<"1 ";
                } else if(this->gameBoard[r][c] == 2) {
                    cout<<"2 ";
                } else {
                    cout<<"0 ";
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }
    
    void initGameBoard(int row, int col) {
        gameBoard = vector<vector<int>>(row, vector<int>(col, 0));
    }
    
    // Checks whether or not the player win the game after the placement.
    bool checkWin(int row, int col, int playerId) {
        int consectiveCount = 0;
        // check horizontal
        for(int c = 0; c < this->colNum; ++c) {
            if(this->gameBoard[row][c] == playerId) {
                consectiveCount += 1;
            } else {
                consectiveCount = 0; // reset the consectiveCount to zero.
            }
            if(consectiveCount == this->n) {
                return true;
            }
        }
        
        // check vertical
        consectiveCount = 0;
        for(int r = 0; r < this->rowNum; ++r) {
            if(this->gameBoard[r][col] == playerId) {
                consectiveCount += 1;
            } else {
                consectiveCount = 0;
            }
            if(consectiveCount == this->n) {
                return true;
            }
        }
        
        // check diag
        consectiveCount = 0;
        for(int r = 0; r < this->rowNum; ++r) {
            int c = col-row+r;
            if(c >= 0 and c < this->colNum and this->gameBoard[r][c] == playerId) {
                consectiveCount += 1;
            } else {
                consectiveCount = 0;
            }
            if(consectiveCount == this->n) {
                return true;
            }
        }
        
        // check antiDiag
        consectiveCount = 0;
        for(int r = 0; r < this->rowNum; ++r) {
            int c = row + col - r;
            if(c >= 0 and c < this->colNum and this->gameBoard[r][c] == playerId) {
                consectiveCount += 1;
            } else {
                consectiveCount = 0;
            }
            if(consectiveCount == this->n) {
                return true;
            }
        }
        return false;
    }
    
    vector<vector<int>> gameBoard;
    int rowNum;
    int colNum;
    int n;
};


#endif /* connectN_h */
