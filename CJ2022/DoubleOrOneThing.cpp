// Created by Victor Rogulenko
// Date and time: 04:38 09/04/2022

#include <bits/stdc++.h>
using namespace std;

#define USE_STANDARD_IO true
int casenum = 1;

void solve() {
    string s;
    cin >> s;
    string ans(1, s[s.size()-1]);
    int i = s.size()-2;
    while (i >= 0) {
        ans = s[i] + ans;
        string new_s = s[i] + ans;
        if (new_s < ans) {
            ans = new_s;
        }
        i--;
    }
    cout << "Case #" << casenum << ": " << ans << endl;
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