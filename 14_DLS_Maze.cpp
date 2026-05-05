#include <bits/stdc++.h>
using namespace std;

int n, m;
int limit = 3;

vector<vector<int>> maze;
vector<vector<int>> vis;
vector<pair<int,int>> path;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool dls(int x, int y, int ex, int ey, int depth) {
    if(depth > limit) return false;

    if(x<0 || y<0 || x>=n || y>=m) return false;
    if(maze[x][y] == 1 || vis[x][y]) return false;

    vis[x][y] = 1;
    path.push_back({x,y});

    if(x == ex && y == ey) return true;

    for(int i=0;i<4;i++) {
        if(dls(x + dx[i], y + dy[i], ex, ey, depth + 1)) return true;
    }

    path.pop_back();
    return false;
}

int main() {
    cin >> n >> m;

    maze.assign(n, vector<int>(m));
    vis.assign(n, vector<int>(m, 0));

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> maze[i][j];

    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;

    if(dls(sx, sy, ex, ey, 0)) {
        for(auto p : path) {
            cout << "(" << p.first << "," << p.second << ")\n";
        }
    } else {
        cout << "No path within depth limit\n";
    }

    return 0;
}

/*
3 3
0 0 0
1 1 0
0 0 0
0 0 0 2
*/