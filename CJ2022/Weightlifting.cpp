// Created by Victor Rogulenko
// Date and time: 16:49 11/04/2022

#include <bits/stdc++.h>
using namespace std;
int casenum = 1;

//Uncomment to use standard input/output:
#define USE_STANDARD_IO true
const int INF = 1000000000;

void solve() {
    // read inputs
    int E, W;
    cin >> E >> W;
    vector<int> empty_stack(W, 0);
    vector<vector<int>> exercises;
    exercises.push_back(empty_stack);
    for (int i = 0; i < E; i++) {
        vector<int> current_stack;
        for (int j = 0; j < W; j++) {
            int Xij;
            cin >> Xij;
            current_stack.push_back(Xij);
        }
        exercises.push_back(current_stack);
    }
    exercises.push_back(empty_stack);

    // precompute comm_weights[l,r] = total number of weights common for all exercises
    // from l to r inclusive
    vector<vector<int>> comm_weights(E+2, vector<int>(E+2, 0));
    for (int l = 1; l <= E; l++) {
        vector<int> current_common_weights = exercises[l];
        int current_weight = 0;
        for (auto wt : current_common_weights) {
            current_weight += wt;
        }
        comm_weights[l][l] = current_weight;
        for (int r = l+1; r <= E; r++) {
            for (auto wt_id = 0; wt_id < W; wt_id++) {
                current_weight -= (current_common_weights[wt_id] - min(current_common_weights[wt_id], exercises[r][wt_id]));
                current_common_weights[wt_id] = min(current_common_weights[wt_id], exercises[r][wt_id]);
            }
            comm_weights[l][r] = current_weight;
        }
    }

    // for (int l = 0; l <= E+1; l++) {
    //     for (int r = 0; r <= E+1; r++) {
    //         cout << comm_weights[l][r] << " ";
    //     }
    //     cout << endl;
    // }

    // find the min number of operations needed for completing exercises
    vector<vector<int>> min_ops(E+2, vector<int>(E+2, INF));
    for (int l = 0; l <= E+1; l++) {
        min_ops[l][l] = 0;
    }
    for (int l = E; l >= 0; l--) {
        for (int r = l+1; r <= E+1; r++) {
            int curval = INF;
            for (int x = l; x < r; x++) {
                curval = min(curval, min_ops[l][x] + min_ops[x+1][r] + 
                    2 * (comm_weights[l][x] + comm_weights[x+1][r] - 2 * comm_weights[l][r]));
            }
            min_ops[l][r] = curval;
        }
    }

    // for (int l = 0; l <= E+1; l++) {
    //     for (int r = 0; r <= E+1; r++) {
    //         cout << min_ops[l][r] << " ";
    //     }
    //     cout << endl;
    // }

    cout << "Case #" << casenum << ": " << min_ops[0][E+1] << endl;
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