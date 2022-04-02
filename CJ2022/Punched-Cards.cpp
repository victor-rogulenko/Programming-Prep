// Created by Victor Rogulenko
// Date and time: <press F5 to add> 20:31 01/04/2022

#include <bits/stdc++.h>
using namespace std;

//#define USE_STANDARD_IO true
int casenum = 1;

void solve() {
    int R, C;
    cin >> R >> C;
    cout << "Case #" << casenum << ":" << endl << "..";
    casenum++;
    for (int j = 0; j < C; j++) {
        if (j == 0) {
            cout << "+";
        } else {
            cout << "-+";
        }
    }
    cout << endl;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if ((i == 0) & (j == 0)) {
                cout << ".";
            } else if (j == 0) {
                cout << "|";
            }
            cout << ".|";
        }
        cout << endl << "+";
        for (int j = 0; j < C; j++) {
            cout << "-+";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    #ifndef USE_STANDARD_IO
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int T = 0;
    cin >> T;
    while (T--) solve();
    return 0;
}