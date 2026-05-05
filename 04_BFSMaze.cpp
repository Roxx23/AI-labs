#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> maze(n, vector<int>(m));

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> maze[i][j];

    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;

    queue<pair<pair<int,int>, vector<pair<int,int>>>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    q.push({{sx, sy}, {{sx, sy}}});
    vis[sx][sy] = 1;

    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};

    while(!q.empty()) {
        auto curr = q.front();
        q.pop();

        int x = curr.first.first;
        int y = curr.first.second;

        if(x == ex && y == ey) {
            for(auto p : curr.second) {
                cout << "(" << p.first << "," << p.second << ")\n";
            }
            return 0;
        }

        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx>=0 && ny>=0 && nx<n && ny<m && maze[nx][ny]==0 && !vis[nx][ny]) {
                vis[nx][ny] = 1;
                auto path = curr.second;
                path.push_back({nx, ny});
                q.push({{nx, ny}, path});
            }
        }
    }

    cout << "No path found\n";
    return 0;
}

/*
5 5    
0 1 0 0 0
0 1 0 1 0
0 0 0 1 0
1 1 0 0 0
0 0 0 1 0
0 0 4 4
*/