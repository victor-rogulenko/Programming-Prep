// Created by Victor Rogulenko
// Date and time: 15:19 15/04/2022

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
int casenum = 0;
i64 MAX = 360*12*10000000000;

//Uncomment to use standard input/output:
#define USE_STANDARD_IO true

void PrintAns(int casenum, int hh, int mm, int ss, i64 ns) {
    cout << "Case #" << casenum << ": " << hh << " " << mm << " " << ss << " " << ns << endl;
}

void solve() {
    casenum++;
    vector<i64> hands(3);
    for (auto& p : hands) cin >> p;
    sort(hands.begin(), hands.end());
    hands[2] -= hands[0];
    hands[1] -= hands[0];
    hands[0] = 0;
    
    vector<vector<i64>> candidates;
    candidates.push_back(hands);
    hands[0] += MAX;
    candidates.push_back(hands);
    hands[1] += MAX;
    candidates.push_back(hands);
    hands[2] += MAX;
    candidates.push_back(hands);

    for (auto hd : candidates) {
        vector<int> ind = {0, 1, 2};
        do {
            i64 A = hd[ind[0]];
            i64 B = hd[ind[1]];
            i64 C = hd[ind[2]];
            // cout << "A = " << A << ", B = " << B << ", C = " << C << endl;

            for (int ss = 0; ss < 60; ss++) {
                for (int mm = 0; mm < 60; mm++) {
                    for (int hh = 0; hh < 12; hh++) {
                        i64 ns = (B - A - (MAX*mm/60 + MAX*ss/60/60) + 
                            (MAX*hh/12 + MAX*mm/12/60 + MAX*ss/12/60/60))/11;
                        i64 X = B - MAX*mm/60 - MAX*ss/60/60 - 12*ns;
                        i64 check = C - MAX*ss/60 - 720*ns - X;
                        // if ((hh == 0) & (mm == 30) & (ss == 0)) {
                        //     cout << "X = " << float(X)/MAX << ", ns = " << ns << ", check = " << check << endl;
                        // }
                        if ((check == 0) & (ns >= 0) & (ns < 1000000000) & (X >= 0) & (X < 2*MAX)) {
                            // cout << "Answer found! X = " << float(X)/MAX << ", ns = " << ns << ", check = " << check << endl;
                            PrintAns(casenum, hh, mm, ss, ns);
                            return;
                        }


                    }
                }
            }         
        } while (next_permutation(ind.begin(), ind.end()));
        // cout << "*****" << endl;
    }
    cout << "Case #" << casenum << ": value not found" << endl;
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