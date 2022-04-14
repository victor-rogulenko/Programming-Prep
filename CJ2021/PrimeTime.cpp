// Created by Victor Rogulenko
// Date and time: 10:50 14/04/2022

#include <bits/stdc++.h>
using namespace std;
int casenum = 1;

//Uncomment to use standard input/output:
#define USE_STANDARD_IO true

int M;
vector<int> P;
vector<long long int> N;

long long int dp(int cur, long long int sum, long long int product) {
    // cout << "cur = " << cur << ", sum = " << sum << ", product = " << product << endl;
        if ((product == sum) & (cur == M)) {
        return product;
    }
    if ((product > sum) | (cur >= M)) {
        return 0;
    }

    long long int res = dp(cur+1, sum, product);
    long long int new_element = 1;

    for (long long int j = 1; j <= N[cur]; j++) {
        new_element *= P[cur];
        if (product*new_element > sum) {
            break;
        }
        long long int new_res = dp(cur+1, sum - P[cur]*j, product*new_element);
        if (new_res > res) {
            res = new_res;
        }
    }

    return res;
}

void solve() {
    long long int res = 0;
    long long int sum = 0;
    cin >> M;
    P = vector<int>(M);
    N = vector<long long int>(M);
    for (auto i = 0; i < M; i++) {
        cin >> P[i] >> N[i];
        sum += P[i]*N[i];
    }

    res = dp(0, sum, 1);

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