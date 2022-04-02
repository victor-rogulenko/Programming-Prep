// Created by Victor Rogulenko
// Date and time: 05:53 02/04/2022

#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;
int casenum = 1;

//#define USE_STANDARD_IO true

void solve() {
    int n;
    cin >> n;
    vector<int> fun(n+1);
    fun[0] = 0;
    vector<int> edge(n+1);
    vector<vector<int>> back_edge(n+1);
    for (int i = 1; i < n+1; i++) {
        cin >> fun[i];
    }
    for (int i = 1; i < n+1; i++) {
        cin >> edge[i];
        back_edge[edge[i]].push_back(i);
    }
    vector<int> minmaxfun(n+1, INF);
    vector<int> parent(n+1);
    for (int i = 0; i < n+1; i++) parent[i] = i;
    for (int i = n; i >=0; i--) {
        for (auto& v : back_edge[i]) {
            if (minmaxfun[i] > minmaxfun[v]) {
                minmaxfun[i] = minmaxfun[v];
                parent[i] = parent[v];
            }
        }
        if (minmaxfun[i] == INF) minmaxfun[i] = fun[i];
        minmaxfun[i] = max(minmaxfun[i], fun[i]);
    }
    // for (int i = 0; i < n+1; i++) {
    //     cout << parent[i] << " ";
    // }
    // cout << endl;
    unsigned long int res = 0;
    for (int i = 0; i < n+1; i++) {
        int v = parent[i];
        int current_fun = 0;
        while ((v != 0) & (fun[v] != 0)) {
            if (current_fun < fun[v]) current_fun = fun[v];
            fun[v] = 0;
            v = edge[v];
        }
        res += current_fun;
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