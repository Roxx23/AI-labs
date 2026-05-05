#include <bits/stdc++.h>
using namespace std;

string goal = "123456780";

int h(string s) {
    int cnt = 0;
    for(int i=0;i<9;i++) {
        if(s[i] != '0' && s[i] != goal[i]) cnt++;
    }
    return cnt;
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

    priority_queue<pair<int, vector<string>>, vector<pair<int, vector<string>>>, greater<>> pq;
    set<string> vis;

    pq.push({h(start), {start}});

    while(!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        string s = curr.second.back();

        if(vis.count(s)) continue;
        vis.insert(s);

        if(s == goal) {
            for(auto st : curr.second) {
                printBoard(st);
            }
            return 0;
        }

        vector<string> next = getNext(s);

        for(auto n : next) {
            if(!vis.count(n)) {
                auto path = curr.second;
                path.push_back(n);
                pq.push({h(n), path});
            }
        }
    }

    cout << "No solution\n";
    return 0;
}

// 1 2 3 4 0 6 7 5 8