#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> graph[i][j];

    vector<int> h(n);
    for(int i=0;i<n;i++) cin >> h[i];

    int start, goal;
    cin >> start >> goal;

    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> pq;
    set<int> vis;

    pq.push({h[start], {start}});

    while(!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        int node = curr.second.back();

        if(vis.count(node)) continue;
        vis.insert(node);

        if(node == goal) {
            for(int x : curr.second) cout << x << " ";
            cout << "\n";
            return 0;
        }

        for(int i=0;i<n;i++) {
            if(graph[node][i] != 0 && !vis.count(i)) {
                auto path = curr.second;
                path.push_back(i);
                pq.push({h[i], path});
            }
        }
    }

    cout << "No path found\n";
    return 0;
}

/*
5
0 1 4 0 0
1 0 2 5 0
4 2 0 1 3
0 5 1 0 2
0 0 3 2 0
7 6 2 1 0
0 4

*/