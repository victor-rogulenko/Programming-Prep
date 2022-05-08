// LeetCode: Weekly Contest 292, 6058. Count Number of Texts
// Created by Victor Rogulenko
// May 08, 2022

#include <cassert>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <iostream>

const int modulo = (int)(1e9) + 7;
const int shift = 5;

int countTexts(std::string pressedKeys) {

    const std::vector<int> passback{0, 0, 3, 3, 3, 3, 3, 4, 3, 4};

    std::vector<long long int> num_texts(pressedKeys.length() + 10, 0);
    for (int idx = 0; idx <= shift; ++idx) {
            num_texts[idx] = 1;
    }

    int ctr = 1;
    for (int idx = 1; idx < pressedKeys.length(); ++idx) {
        if (pressedKeys[idx] == pressedKeys[idx-1]) {
            ++ctr;
        } else {
            ctr = 1;
        }
        if (ctr >= passback[(int)(pressedKeys[idx]) - (int)('0')]) {
            ctr = passback[(int)(pressedKeys[idx]) - (int)('0')];
        }
        // std::cout << "ctr = " << ctr << "\n";
        for (int jdx = 1; jdx <= ctr; ++jdx) {
            num_texts[idx+shift] += num_texts[idx+shift-jdx];
            num_texts[idx+shift] %= modulo;
            // std::cout << "adding previous values: " << num_texts[idx+shift-jdx] % modulo << "\n";
        }
        // std::cout << num_texts[idx+shift] << "\n";
    }
    // std::cout << num_texts[pressedKeys.length()-1 + shift] << "\n";
    return num_texts[pressedKeys.length()-1 + shift];        
}

// 1 <= pressedKeys.length <= 105
// pressedKeys only consists of digits from '2' - '9'.

void RunTestCases() {
    assert(countTexts("22233") == 8);
    assert(countTexts("55555555999977779555") == 20736);
    assert(countTexts("222222222222222222222222222222222222") == 82876089);
}

int main() {
    RunTestCases();
    return 0;
}