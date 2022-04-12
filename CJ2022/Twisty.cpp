// Created by Victor Rogulenko
// Date and time: 10:45 12/04/2022

#include <bits/stdc++.h>
#include <random>
using namespace std;

#define USE_STANDARD_IO true

void solve() {
    long long int N, K;
    cin >> N >> K;
    long long int loc, e, sum_edges_T, sum_edges_W;
    cin >> loc >> sum_edges_T;
    sum_edges_W = 0;
    set<int> visited;
    visited.insert(loc);

    vector<int> node_ord(N);
    iota(node_ord.begin(), node_ord.end(), 1);
    shuffle(node_ord.begin(), node_ord.end(), mt19937{random_device{}()});
    
    int it = 0;
    int Tctr = 0;
    int Wctr = 0;
    auto limit = K;
    while (it < min(limit, N)) {
        if (visited.find(node_ord[it]) != visited.end()) {
            limit++;
            it++;
            continue;
        }
        cout << "T " << node_ord[it] << endl;
        cin >> loc >> e;
        visited.insert(loc);
        sum_edges_T += e;
        Tctr++;
        it++;
        if (it < limit) {
            cout << "W" << endl;
            cin >> loc >> e;
            if (visited.find(loc) == visited.end()) {
                visited.insert(loc);
                sum_edges_W += e;
                Wctr++;
            }
            it++;
        }
    }

    long long int result = sum_edges_W + sum_edges_T + 
                           round(sum_edges_T / Tctr * (N - Tctr - Wctr));

    cout << "E " << result/2 << endl;
    //cout << min_val << " " << max_val << endl;
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