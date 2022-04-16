// Created by Victor Rogulenko
// [2022-04-16 15:01]  

#include <bits/stdc++.h>
using namespace std;
int casenum = 1;
const int MAXITER = 1000;
const int MAXNUM = 10000;

//Uncomment to use standard input/output:
#define USE_STANDARD_IO true

void solve() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> U(N);
    for (auto& v : U) cin >> v;

    auto how_many_needed = [&](int cur) -> int {
        return cur < N ? U[cur] : 0;
    };

    auto X_works = [&](int X) {
        vector<int> storage(X+1, 0);
        storage[X] = 1;
        while (X >= 0) {
            storage[X] = min(storage[X], MAXNUM);
            if (storage[X] < how_many_needed(X)) return false;
            storage[X] -= how_many_needed(X);
            if (X - A >= 0) storage[X-A] += storage[X];
            if (X - B >= 0) storage[X-B] += storage[X];
            X--;
        }
        return true;
    };
    
    int iter = 0;
    int res = N - 1;
    while (!X_works(res) && iter++ < MAXITER) res++;

    cout << "Case #" << casenum << ": " << (iter >= MAXITER ? "IMPOSSIBLE" : to_string(res+1)) << endl;
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