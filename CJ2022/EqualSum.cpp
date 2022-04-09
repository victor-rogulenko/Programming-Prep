// Created by Victor Rogulenko
// Date and time: 04:38 09/04/2022

#include <bits/stdc++.h>
using namespace std;

#define USE_STANDARD_IO true

void solve() {
    int n, n1;
    cin >> n;
    n1 = n;
    vector<long long int> res;
    long long int cur = 1;
    while (cur < 1000000000) {
        res.push_back(cur);
        n1--;
        cur = cur*2;
        //cout << cur << endl;
    }
    //cout << "OK";
    cur = 1000000000 - 1;
    while (n1 > 0) {
        res.push_back(cur);
        cur--;
        n1--;
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cin >> cur;
        res.push_back(cur);
    }
    sort(res.begin(), res.end());

    vector<long long int> answer;
    long long int sum = 0;
    for (int i = res.size()-1; i >=0; i--) {
        if (sum <= 0) {
            sum += res[i];
            answer.push_back(res[i]);
        } else {
            sum -= res[i];
        }
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

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