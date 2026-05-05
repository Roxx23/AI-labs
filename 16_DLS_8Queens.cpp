#include <bits/stdc++.h>
using namespace std;

int n;
int limit = 3;
vector<int> board;

bool isSafe(int row, int col) {
    for(int i=0;i<row;i++) {
        if(board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

bool dls(int row) {
    if(row > limit) return false;

    if(row == n) return true;

    for(int col=0; col<n; col++) {
        if(isSafe(row, col)) {
            board[row] = col;
            if(dls(row + 1)) return true;
        }
    }
    return false;
}

int main() {
    cin >> n;
    board.assign(n, -1);

    if(dls(0)) {
        for(int i=0;i<=limit && i<n;i++) {
            for(int j=0;j<n;j++) {
                if(board[i] == j) cout << "Q ";
                else cout << ". ";
            }
            cout << "\n";
        }
    } else {
        cout << "No solution within depth limit\n";
    }

    return 0;
}

// 8