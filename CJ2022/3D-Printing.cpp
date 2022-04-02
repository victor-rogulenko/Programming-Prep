// Created by Victor Rogulenko
// Date and time: 05:13 02/04/2022

#include <bits/stdc++.h>
using namespace std;
#define USE_STANDARD_IO true
const int goal = 1000000;
int casenum = 1;

void solve() {
    vector<int> colors(4, goal);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            int new_color;
            cin >> new_color;
            colors[j] = min(colors[j], new_color);
        }
    }
    cout << "Case #" << casenum << ": ";
    if (accumulate(colors.begin(), colors.end(), 0) < goal) {
        cout << "IMPOSSIBLE";
    } else {
        int used = goal;
        for (int i = 0; i < 4; i++) {
            colors[i] = min(used, colors[i]);
            used -= colors[i];
            cout << colors[i] << " ";
        }
    }
    cout << endl;
    casenum++;
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