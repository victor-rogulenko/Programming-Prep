// Created by Victor Rogulenko
// Date and time: 12:08 18/04/2022

#include <bits/stdc++.h>
using namespace std;
int casenum = 1;

//Uncomment to use standard input/output:
#define USE_STANDARD_IO true

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for (auto& p : P) {
      cin >> p;
    }
    sort(P.begin(), P.end());
    vector<int> dist, dist_pair;
    for (auto i = 0; i < N-1; i++) {
        int right = P[i] + ((P[i+1] - P[i]) >> 1);
        dist.push_back(right - P[i]);
        dist_pair.push_back(P[i+1]-P[i]-1);
    }
    dist.push_back(P[0] - 1);
    dist.push_back(K - P[N-1]);
    dist_pair.push_back(0);
    sort(dist.rbegin(), dist.rend());
    sort(dist_pair.rbegin(), dist_pair.rend());
    double res = float(max(dist[0] + dist[1], dist_pair[0])) / K;

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