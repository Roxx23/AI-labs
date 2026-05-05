#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> color;

bool isSafe(int node, int c) {
    for(int i=0;i<n;i++) {
        if(graph[node][i] == 1 && color[i] == c)
            return false;
    }
    return true;
}

bool solve(int node) {
    if(node == n) return true;

    for(int c=1; c<=m; c++) {
        if(isSafe(node, c)) {
            color[node] = c;
            if(solve(node + 1)) return true;
            color[node] = 0;
        }
    }
    return false;
}

int main() {
    cin >> n >> m;

    graph.assign(n, vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> graph[i][j];

    color.assign(n, 0);

    if(solve(0)) {
        for(int i=0;i<n;i++) {
            cout << "Node " << i << " -> Color " << color[i] << "\n";
        }
    } else {
        cout << "No solution\n";
    }

    return 0;
}

/*
4 3
0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0
*/