#include <bits/stdc++.h>
using namespace std;

string s1, s2, s3;
set<char> letters;
vector<char> chars;
map<char,int> mp;
bool used[10];

long long getVal(string s) {
    long long num = 0;
    for(char c : s) num = num * 10 + mp[c];
    return num;
}

bool solve(int idx) {
    if(idx == chars.size()) {
        if(mp[s1[0]] == 0 || mp[s2[0]] == 0 || mp[s3[0]] == 0) return false;

        long long n1 = getVal(s1);
        long long n2 = getVal(s2);
        long long n3 = getVal(s3);

        if(n1 + n2 == n3) {
            cout << n1 << " + " << n2 << " = " << n3 << "\n";
            return true;
        }
        return false;
    }

    for(int d = 0; d <= 9; d++) {
        if(!used[d]) {
            used[d] = true;
            mp[chars[idx]] = d;

            if(solve(idx + 1)) return true;

            used[d] = false;
        }
    }
    return false;
}

int main() {
    cin >> s1 >> s2 >> s3;

    for(char c : s1) letters.insert(c);
    for(char c : s2) letters.insert(c);
    for(char c : s3) letters.insert(c);

    for(char c : letters) chars.push_back(c);

    if(chars.size() > 10) {
        cout << "No solution\n";
        return 0;
    }

    memset(used, false, sizeof(used));

    if(!solve(0)) {
        cout << "No solution\n";
    }

    return 0;
}

// SEND MORE MONEY