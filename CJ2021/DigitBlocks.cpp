// Created by Victor Rogulenko
// [2022-04-16 18:10] 
// Based on solution by Errichto
// https://codingcompetitions.withgoogle.com/codejam/submissions/0000000000435baf/00000000005a5fb2

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 21;
double dp[MAXN][MAXN][MAXN][MAXN];
int next_move[MAXN][MAXN][MAXN][MAXN][10];
int T, N, B;
int64_t P;

void prepare() {
    cin >> T >> N >> B >> P;
    for (int zero_left = N; zero_left >= 0; zero_left--) {
        for (int one_left = N - zero_left; one_left >= 0; one_left--) {
            for (int two_left = N - one_left - zero_left; two_left >= 0; two_left--) {
                for (int height_small = B - 3; height_small >= 0; height_small--) {
                    if (zero_left + one_left + two_left == N && height_small != 0) {
                        continue;
                    }
                    //cout << dp[zero_left][one_left][two_left][height_small] << endl;

                    for (int current_digit = 0; current_digit < 10; current_digit++) {
                        double best = -1;
                        if (one_left != 0) {
                            double cur = dp[zero_left + 1][one_left - 1][two_left][height_small] + 0.1 * current_digit;
                            if (cur > best) {
                                best = cur;
                                next_move[zero_left][one_left][two_left][height_small][current_digit] = 14;
                            }
                        }
                        if (two_left != 0) {
                            double cur = dp[zero_left][one_left + 1][two_left - 1][height_small] + 0.01 * current_digit;
                            if (cur > best) {
                                best = cur;
                                next_move[zero_left][one_left][two_left][height_small][current_digit] = 13;
                            }
                        }
                        if (zero_left + one_left + two_left != N) {
                            if (height_small == B - 3) {
                                double cur = dp[zero_left][one_left][two_left + 1][0] + 0.001 * current_digit;
                                if(cur > best) {
                                    best = cur;
                                    next_move[zero_left][one_left][two_left][height_small][current_digit] = height_small;
                                }
                            }
                            else {
                                double cur = dp[zero_left][one_left][two_left][height_small + 1] + 
                                                (height_small == B - 4 ? 0.0001 * current_digit : 0);
                                if (cur > best) {
                                    best = cur;
                                    next_move[zero_left][one_left][two_left][height_small][current_digit] = height_small;
                                }
                            }
                        }
                        dp[zero_left][one_left][two_left][height_small] += best / 10;
                    }
                }
            }
        }
    }
}

void solve() {
    int zero_left = 0, one_left = 0, two_left = 0, height_small = 0;
    vector<int> height(N + 1);
    for (int j = 0; j < N * B; j++) {
        int current_digit;
        cin >> current_digit;
        for (int i = 1; i <= N; i++) {
            if (height[i] == next_move[zero_left][one_left][two_left][height_small][current_digit]) {
                if (height[i] == 14) {
                    zero_left++;
                    one_left--;
                }
                else if (height[i] == 13) {
                    one_left++;
                    two_left--;
                }
                else {
                    height_small++;
                    if (height_small == 13) {
                        two_left++;
                        height_small = 0;
                    }
                }
                cout << i << endl;
                height[i]++;
                break;
            }
        }
    }
}

int main() {
    prepare();
    while (T--) solve();
}