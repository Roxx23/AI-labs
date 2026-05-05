#include <bits/stdc++.h>
using namespace std;

struct State {
    int m, c, b;
};

bool valid(int m, int c, int M, int C) {
    int m2 = M - m;
    int c2 = C - c;

    if(m < 0 || c < 0 || m > M || c > C) return false;

    if(m > 0 && c > m) return false;
    if(m2 > 0 && c2 > m2) return false;

    return true;
}

int main() {
    int M, C;
    cin >> M >> C;

    State start = {M, C, 0};
    State goal = {0, 0, 1};

    vector<pair<int,int>> moves = {{1,0},{2,0},{0,1},{0,2},{1,1}};

    queue<pair<State, vector<State>>> q;
    set<tuple<int,int,int>> vis;

    q.push({start, {start}});
    vis.insert({start.m, start.c, start.b});

    while(!q.empty()) {
        auto curr = q.front();
        q.pop();

        State s = curr.first;

        if(s.m == goal.m && s.c == goal.c && s.b == goal.b) {
            for(auto st : curr.second) {
                cout << "(" << st.m << "," << st.c << "," << st.b << ")\n";
            }
            return 0;
        }

        for(auto mv : moves) {
            int nm, nc, nb;

            if(s.b == 0) {
                nm = s.m - mv.first;
                nc = s.c - mv.second;
                nb = 1;
            } else {
                nm = s.m + mv.first;
                nc = s.c + mv.second;
                nb = 0;
            }

            if(valid(nm, nc, M, C)) {
                if(vis.count({nm, nc, nb}) == 0) {
                    vis.insert({nm, nc, nb});
                    auto path = curr.second;
                    path.push_back({nm, nc, nb});
                    q.push({{nm, nc, nb}, path});
                }
            }
        }
    }

    cout << "No solution\n";
    return 0;
}

/*
3 3
*/