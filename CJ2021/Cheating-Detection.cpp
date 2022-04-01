// Created by Victor Rogulenko
// Date and time: 15:38 01/04/2022

#include <bits/stdc++.h>
using namespace std;

const int qusers = 100;
const int qquestions = 10000;
int casenum = 1;

#define USE_STANDARD_IO true

void solve() {
    vector<string> user_ans;
    vector<int> qn_difficulty(qquestions, 0);
    vector<double> user_res(qusers, 0);

    for (int i = 0; i < qusers; i++) {
        string s;
        cin >> s;
        user_ans.push_back(s);
        for (int j = 0; j < qquestions; j++) {
            if (s[j] == '0') qn_difficulty[j]++;
        }
    }

    for (int i = 0; i < qusers; i++) {
        double solved_sum = 0;
        double solved_cnt = 0;
        double error_sum = 0;
        double error_cnt = 0;

        for (int j = 0; j < qquestions; j++) {
            if (user_ans[i][j] == '1') {
                solved_sum += qn_difficulty[j];
                solved_cnt++;
            } else {
                error_sum += qn_difficulty[j];
                error_cnt++;
            }
        }

        user_res[i] = solved_sum/solved_cnt - error_sum/error_cnt;
        //user_res[i] = solved_cnt;
    }

    // for (int i = 0; i < user_res.size(); i++) {
    //     cout << i << ": " << user_res[i] << endl;
    // }

    int res = max_element(user_res.begin(), user_res.end()) - user_res.begin() + 1;
    cout << "Case #" << casenum << ": " << res << endl;
    casenum++;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    #ifndef USE_STANDARD_IO
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
	#endif
    int T, P;
    cin >> T >> P;
    while (T--) solve();
	return 0;
}