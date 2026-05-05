#include <bits/stdc++.h>
using namespace std;

struct State {
    int m, c, b;
};

int M, C;
set<tuple<int,int,int>> vis;
vector<State> path;

bool valid(int m, int c) {
    int m2 = M - m;
    int c2 = C - c;

    if(m < 0 || c < 0 || m > M || c > C) return false;

    if(m > 0 && c > m) return false;
    if(m2 > 0 && c2 > m2) return false;

    return true;
}

bool dfs(State s) {
    if(vis.count({s.m, s.c, s.b})) return false;
    vis.insert({s.m, s.c, s.b});
    path.push_back(s);

    if(s.m == 0 && s.c == 0 && s.b == 1) return true;

    vector<pair<int,int>> moves = {{1,0},{2,0},{0,1},{0,2},{1,1}};

    for(auto mv : moves) {
        State next;

        if(s.b == 0) {
            next.m = s.m - mv.first;
            next.c = s.c - mv.second;
            next.b = 1;
        } else {
            next.m = s.m + mv.first;
            next.c = s.c + mv.second;
            next.b = 0;
        }

        if(valid(next.m, next.c)) {
            if(dfs(next)) return true;
        }
    }

    path.pop_back();
    return false;
}

int main() {
    cin >> M >> C;

    State start = {M, C, 0};

    if(dfs(start)) {
        for(auto s : path) {
            cout << "(" << s.m << "," << s.c << "," << s.b << ")\n";
        }
    } else {
        cout << "No solution\n";
    }

    return 0;
}

// 3 3