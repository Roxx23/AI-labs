#include <bits/stdc++.h>
using namespace std;

struct State {
    int x, y;
};

int main() {
    int cap1, cap2, target;
    cin >> cap1 >> cap2 >> target;

    queue<pair<State, vector<State>>> q;
    set<pair<int,int>> visited;

    State start = {0,0};
    q.push({start, {start}});
    visited.insert({0,0});

    while(!q.empty()) {
        auto curr = q.front();
        q.pop();

        int x = curr.first.x;
        int y = curr.first.y;

        if(x == target || y == target) {
            for(auto s : curr.second) {
                cout << "(" << s.x << "," << s.y << ")\n";
            }
            return 0;
        }

        vector<State> nextStates;

        nextStates.push_back({cap1, y});
        nextStates.push_back({x, cap2});
        nextStates.push_back({0, y});
        nextStates.push_back({x, 0});

        int pour = min(x, cap2 - y);
        nextStates.push_back({x - pour, y + pour});

        pour = min(y, cap1 - x);
        nextStates.push_back({x + pour, y - pour});

        for(auto ns : nextStates) {
            if(visited.count({ns.x, ns.y}) == 0) {
                visited.insert({ns.x, ns.y});
                auto path = curr.second;
                path.push_back(ns);
                q.push({ns, path});
            }
        }
    }

    cout << "No solution\n";
    return 0;
}

// 4 3 2