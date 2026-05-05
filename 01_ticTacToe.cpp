#include <bits/stdc++.h>
using namespace std;

char board[3][3];

void init() {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            board[i][j] = ' ';
}

void printBoard() {
    cout << "\n";
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cout << board[i][j];
            if(j<2) cout << " | ";
        }
        cout << "\n";
        if(i<2) cout << "--+---+--\n";
    }
    cout << "\n";
}

bool checkWin(char p) {
    for(int i=0;i<3;i++) {
        if(board[i][0]==p && board[i][1]==p && board[i][2]==p) return true;
        if(board[0][i]==p && board[1][i]==p && board[2][i]==p) return true;
    }
    if(board[0][0]==p && board[1][1]==p && board[2][2]==p) return true;
    if(board[0][2]==p && board[1][1]==p && board[2][0]==p) return true;
    return false;
}

bool isFull() {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j]==' ') return false;
    return true;
}

int minimax(bool isMax) {
    if(checkWin('O')) return 1;
    if(checkWin('X')) return -1;
    if(isFull()) return 0;

    if(isMax) {
        int best = -1000;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(board[i][j]==' ') {
                    board[i][j]='O';
                    best = max(best, minimax(false));
                    board[i][j]=' ';
                }
            }
        }
        return best;
    } else {
        int best = 1000;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(board[i][j]==' ') {
                    board[i][j]='X';
                    best = min(best, minimax(true));
                    board[i][j]=' ';
                }
            }
        }
        return best;
    }
}

pair<int,int> bestMove() {
    int bestVal = -1000;
    pair<int,int> move = {-1,-1};

    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(board[i][j]==' ') {
                board[i][j]='O';
                int val = minimax(false);
                board[i][j]=' ';
                if(val > bestVal) {
                    bestVal = val;
                    move = {i,j};
                }
            }
        }
    }
    return move;
}

void twoPlayer() {
    init();
    int turn = 0;
    while(true) {
        printBoard();
        int r,c;
        cout << "Enter row and col: ";
        cin >> r >> c;
        if(board[r][c]!=' ') continue;

        if(turn%2==0) board[r][c]='X';
        else board[r][c]='O';

        if(checkWin(board[r][c])) {
            printBoard();
            cout << board[r][c] << " wins\n";
            break;
        }
        if(isFull()) {
            printBoard();
            cout << "Draw\n";
            break;
        }
        turn++;
    }
}

void aiGame() {
    init();
    while(true) {
        printBoard();
        int r,c;
        cout << "Your move: ";
        cin >> r >> c;
        if(board[r][c]!=' ') continue;

        board[r][c]='X';

        if(checkWin('X')) {
            printBoard();
            cout << "You win\n";
            break;
        }

        if(isFull()) {
            printBoard();
            cout << "Draw\n";
            break;
        }

        pair<int,int> m = bestMove();
        board[m.first][m.second] = 'O';

        if(checkWin('O')) {
            printBoard();
            cout << "AI wins\n";
            break;
        }

        if(isFull()) {
            printBoard();
            cout << "Draw\n";
            break;
        }
    }
}

int main() {
    int choice;
    cout << "1. Two Player\n2. vs AI\n";
    cin >> choice;

    if(choice==1) twoPlayer();
    else aiGame();

    return 0;
}