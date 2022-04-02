// Created by Victor Rogulenko
// Date and time: 17:39 02/04/2022

#include <bits/stdc++.h>
#include <random>
using namespace std;

#define USE_STANDARD_IO true

void solve() {
    long long int N, K;
    cin >> N >> K;
    vector<int> edges;
    long long int loc, loc_first, e, sum_edges;
    cin >> loc_first >> e;
    sum_edges = e;
    edges.push_back(e);
    vector<int> node_ord(N);
    iota(node_ord.begin(), node_ord.end(), 1);
    shuffle(node_ord.begin(), node_ord.end(), mt19937{random_device{}()});
    int it = 0;
    auto limit = K;
    while (it < min(limit, N)) {
        if (node_ord[it] != loc_first) {
            cout << "T " << node_ord[it] << endl;
            cin >> loc >> e;
            sum_edges += e;
            edges.push_back(e);
        } else {
            limit++;
        }
        it++;
    }

    if (edges.size() == N) {   
    // if we had enough questions to ask about every node
        cout << "E " << sum_edges/2 << endl;
        return;
    }

    long long int min_val = 0;
    // Min possible number of edges
    int alloc = 0;
    sort(edges.rbegin(),edges.rend());
    for (auto i : edges) {
        alloc -= i;
        alloc = abs(alloc);
    }
    min_val = ((sum_edges - alloc)/2) + alloc + round(sum_edges*(N-K-1)/K/2);

    long long int  max_val = 0;
    // Max possible number of edges
    if (sum_edges <= (N - K - 1) * (K + 1)) {
        max_val = sum_edges + (((N - K - 1) * (N - K - 2))/2);
    } else {
        int leftover = sum_edges - (N - K - 1) * (K + 1);
        // quick but possibly imprecise:
        max_val = (N - K - 1) * (K + 1) + (leftover/2) + (((N - K - 1) * (N - K - 2))/2);
    }
    long long int result;
    if (N < 100) {
        result = min_val;
    } else if (sum_edges > (K*(K-1)/4)) {
        result = max_val;
    } else {
        result = min_val;
    }

    cout << "E " << result << endl;
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