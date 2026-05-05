#include <bits/stdc++.h>
using namespace std;

int cap1, cap2, target;
int limit = 3;

set<pair<int,int>> vis;
vector<pair<int,int>> path;

bool dls(int x, int y, int depth) {
    if(depth > limit) return false;

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
        if(dls(n.first, n.second, depth + 1)) return true;
    }

    path.pop_back();
    return false;
}

int main() {
    cin >> cap1 >> cap2 >> target;

    if(dls(0,0,0)) {
        for(auto p : path) {
            cout << "(" << p.first << "," << p.second << ")\n";
        }
    } else {
        cout << "No solution within depth limit\n";
    }

    return 0;
}

// 4 3 2 -> invalid
// 2 1 1 -> valid