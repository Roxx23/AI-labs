#include <bits/stdc++.h>
using namespace std;

int cap1, cap2, target;
set<pair<int,int>> vis;
vector<pair<int,int>> path;

bool dfs(int x, int y) {
    if(vis.count({x,y})) return false;
    vis.insert({x,y});
    path.push_back({x,y});

    if(x == target || y == target) return true;

    vector<pair<int,int>> next;

    next.push_back({cap1, y});
    next.push_back({x, cap2});
    next.push_back({0, y});
    next.push_back({x, 0});

    int pour = min(x, cap2 - y);
    next.push_back({x - pour, y + pour});

    pour = min(y, cap1 - x);
    next.push_back({x + pour, y - pour});

    for(auto n : next) {
        if(dfs(n.first, n.second)) return true;
    }

    path.pop_back();
    return false;
}

int main() {
    cin >> cap1 >> cap2 >> target;

    if(dfs(0,0)) {
        for(auto p : path) {
            cout << "(" << p.first << "," << p.second << ")\n";
        }
    } else {
        cout << "No solution\n";
    }

    return 0;
}

// 4 3 2