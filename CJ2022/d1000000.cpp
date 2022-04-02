// Created by Victor Rogulenko
// Date and time: 05:49 02/04/2022

#include <bits/stdc++.h>
using namespace std;

//#define USE_STANDARD_IO true
int casenum = 1;

void solve() {
    int N;
    cin >> N;
    vector<int> dice(N);
    for (int i = 0; i < N; i++) {
        cin >> dice[i];
    }
    sort(dice.begin(),dice.end());
    int res = 0;
    for (int i = 0; i < N; i++) {
        res = min(res+1, dice[i]);
    }
    cout << "Case #" << casenum << ": " << res << endl;
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