#include <bits/stdc++.h>
using namespace std;

string goal = "123456780";
set<string> vis;
vector<string> path;

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

bool dfs(string s) {
    if(vis.count(s)) return false;
    vis.insert(s);
    path.push_back(s);

    if(s == goal) return true;

    vector<string> next = getNext(s);

    for(auto n : next) {
        if(dfs(n)) return true;
    }

    path.pop_back();
    return false;
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

    if(dfs(start)) {
        for(auto st : path) {
            printBoard(st);
        }
    } else {
        cout << "No solution\n";
    }

    return 0;
}

// 1 2 3 4 0 6 7 5 8