// Created by Victor Rogulenko
// Date and time: <press F5 to add> 20:31 01/04/2022

#include <bits/stdc++.h>
using namespace std;
int casenum = 1;

//Uncomment to use standard input/output:
//#define USE_STANDARD_IO true


void solve() {
    long long int res = 0;

    // insert code here

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