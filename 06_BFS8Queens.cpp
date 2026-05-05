#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<int> &board, int row, int col) {
    for(int i=0;i<row;i++) {
        if(board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void printBoard(vector<int> &board, int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(board[i] == j) cout << "Q ";
            else cout << ". ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    int n;
    cin >> n;

    queue<vector<int>> q;
    q.push(vector<int>());

    while(!q.empty()) {
        vector<int> curr = q.front();
        q.pop();

        int row = curr.size();

        if(row == n) {
            printBoard(curr, n);
            return 0;
        }

        for(int col=0; col<n; col++) {
            if(isSafe(curr, row, col)) {
                vector<int> next = curr;
                next.push_back(col);
                q.push(next);
            }
        }
    }

    cout << "No solution\n";
    return 0;
}