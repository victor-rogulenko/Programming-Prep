// Created by Victor Rogulenko
// Date and time: 14:37 13/04/2022

#include <bits/stdc++.h>
using namespace std;
int casenum = 1;

//Uncomment to use standard input/output:
//#define USE_STANDARD_IO true

string next(string& s) {
    bool add = true;
    string res = s;

    for (int i = res.size()-1; i >= 0; i--) {
        if (!add) {
            break;
        }
        //cout << "i = " << i << endl;
        //cout << "res[i] = " << res[i] << endl;
        if (res[i] == '9') {
            res[i] = '0';
        } else {
            res[i] = (char)(int(res[i]) + 1);
            add = false;
        }
        // cout << "res[i] = " << res[i] << endl;
    }
    return res;
}

void solve() {
    long long int res = 0;

    int N;
    cin >> N;
    int cur;
    cin >> cur;
    string prev = to_string(cur);
    for (auto i = 1; i < N; i++) {
        int k = 0;
        cin >> cur;
        string curstr = to_string(cur);
        string curstr_h = curstr;
        string curstr_l = curstr;
        // cout << "prev = " << prev << "; cur = " << cur << endl;

        while (curstr_h.size() < prev.size()) {
            curstr_h += '9';
            curstr_l += '0';
            k++;
        }
        if ((curstr_h > prev) & (curstr_l <= prev)) {
            curstr = next(prev);
        } else if ((curstr_h <= prev) & (curstr_h.size() == prev.size())) {
            curstr = curstr_l + '0';
            k++;
        } else {
            curstr = curstr_l;
        }
        // cout << "cur = " << curstr << ", curstr_h = " << curstr_h << ", curstr_l = " << curstr_l<< endl;
        // cout << "k = " << k << endl;
        res += k;
        prev = curstr;
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