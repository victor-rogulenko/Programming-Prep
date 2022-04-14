// Created by Victor Rogulenko
// Date and time: 10:50 14/04/2022

#include <bits/stdc++.h>
using namespace std;
int casenum = 1;

//Uncomment to use standard input/output:
#define USE_STANDARD_IO true

int M;
int max_second_sum = 30000;
vector<int> P;
vector<long long int> N;

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

    for (long long int first = sum; (first >= sum - max_second_sum) & (first > 0); first--) {
        vector<int> factorization(M, 0);
        long long int candidate = first;
        //cout << "first = " << candidate << endl;
        for (int i = 0; i < M; i++) {
            for (int j = 1; j <= N[i]; j++) {
                if (candidate % P[i] == 0) {
                    candidate /= P[i];
                    factorization[i]++;
                } else {
                    break;
                }
            }
        }

        //cout << "candidate = " << candidate << endl;

        if (candidate > 1) {
            continue;
        }

        long long int sum_first = 0;

        for (int i = 0; i < M; i++) {
            if (factorization[i] > N[i]) {
                break;
            }
            sum_first += P[i]*(N[i]-factorization[i]);
        }

        //cout << "sum_first = " << sum_first << endl;

        if ((first == sum_first) & (res < first)) {
            res = first;
        }
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