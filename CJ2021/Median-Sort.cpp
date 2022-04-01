// Created by Victor Rogulenko
// Date and time: 12:35 01/04/2022

#include <bits/stdc++.h>
using namespace std;

int N, Q;

int Inquire(int left, int right, int candidate) {
    cout << left+1 << " " << right+1 << " " << candidate+1 << endl;
    int res;
    cin >> res;
    if (res == -1) exit(0);
    return (res-1);
}

void PrintVector(const vector<int>& v) {
    for (auto it : v) {
        cout << it+1 << " ";
    }
    cout << endl;
}

void Judge() {
    int result;
    cin >> result;
    if (result == -1) exit(0);
}

void PlaceNewIndex(vector<int>& sorted, int j) {
    int s = 0;
    int e = (int)sorted.size() + 1;
    while (s + 1 < e) {
        int midleft = (2*s + e) / 3;
        int midright = (s + 2*e) / 3;
        if (midleft == 0) midleft++;
        while (midright <= midleft) midright++;
        if (midright == (int)sorted.size() + 1) midright--;
        while (midleft >= midright) midleft--;
        int res = Inquire(sorted[midleft-1], sorted[midright-1], j);
        if (res == j) {
            s = max(s, midleft);
            e = min(e, midright);
        } else if(res == sorted[midleft-1]) {
            e = min(e, midleft);
        } else {
            s = max(s, midright);
        }
    }
    sorted.insert(sorted.begin() + s, j);
}

void Solve() {
    vector<int> sorted = {0, 1};
    for (int j = 2; j < N; j++) {
        PlaceNewIndex(sorted, j);
    }
    PrintVector(sorted);
    Judge();
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T >> N >> Q;
    for (int i = 0; i < T; i++) {
        Solve();
    }
	return 0;
}