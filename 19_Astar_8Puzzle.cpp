#include <bits/stdc++.h>
using namespace std;

string goal = "123456780";

int manhattan(string s) {
    int dist = 0;
    for(int i=0;i<9;i++) {
        if(s[i] == '0') continue;
        int val = s[i] - '1';
        int x1 = i / 3, y1 = i % 3;
        int x2 = val / 3, y2 = val % 3;
        dist += abs(x1 - x2) + abs(y1 - y2);
    }
    return dist;
}

vector<string> getNext(string s) {
    vector<string> res;
    int idx = s.find('0');
    int x = idx / 3;
    int y = idx % 3;

    vector<pair<int,int>> moves = {{1,0},{-1,0},{0,1},{0,-1}};

    for(auto m : moves) {
        int nx = x + m.first;
        int ny = y + m.second;

        if(nx>=0 && nx<3 && ny>=0 && ny<3) {
            string t = s;
            swap(t[x*3+y], t[nx*3+ny]);
            res.push_back(t);
        }
    }
    return res;
}

void printBoard(string s) {
    for(int i=0;i<9;i++) {
        cout << s[i] << " ";
        if(i%3==2) cout << "\n";
    }
    cout << "\n";
}

int main() {
    string start = "";
    for(int i=0;i<9;i++) {
        char x;
        cin >> x;
        start += x;
    }

    priority_queue<
        pair<int, pair<string, vector<string>>>,
        vector<pair<int, pair<string, vector<string>>>>,
        greater<>
    > pq;

    set<string> vis;

    pq.push({manhattan(start), {start, {start}}});

    while(!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        string s = curr.second.first;
        vector<string> path = curr.second.second;

        if(vis.count(s)) continue;
        vis.insert(s);

        if(s == goal) {
            for(auto st : path) {
                printBoard(st);
            }
            return 0;
        }

        vector<string> next = getNext(s);

        for(auto n : next) {
            if(!vis.count(n)) {
                vector<string> newPath = path;
                newPath.push_back(n);
                int g = newPath.size();
                int f = g + manhattan(n);
                pq.push({f, {n, newPath}});
            }
        }
    }

    cout << "No solution\n";
    return 0;
}

// Manhattan Distance heuristic

// 1 2 3 4 0 6 7 5 8