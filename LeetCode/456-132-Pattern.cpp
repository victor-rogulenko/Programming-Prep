// LeetCode: 456. 132 Pattern
// Created by Victor Rogulenko
// May 07, 2022

#include <cassert>
#include <vector>
#include <stack>

struct Border {
    Border(int a, int b) : min_(a), max_(b) {};
    int min_, max_;
};

bool find132pattern(const std::vector<int>& nums) {
    if (nums.size() < 3) {
        return false;
    }
    int cur_min = nums[0];
    int cur_max = nums[0];
    std::stack<Border> borders;
    for (auto& elm : nums) {
        if (elm > cur_max) {
            cur_max = elm;
            // If elm is bigger than the previous border, get rid of the previous border. 
            // It won't hava an impact on the result anymore

            while ((!borders.empty()) && (borders.top().max_ < elm)) {
                borders.pop();
            }
            // If elm fits within a previous border, we found the 132 pattern. Return true
            if ((!borders.empty()) && (borders.top().min_ < elm) && 
                (borders.top().max_ > elm)) {
                return true;
            }
        } else if ((elm < cur_max) && (elm > cur_min)) {
            // If elm fits within the current border, return true as well
            return true;
        } else if (elm < cur_min) {
            // If elm is smaller than the current border, stack the current border and start a new one;
            if (cur_min < cur_max) {
                borders.push(Border(cur_min, cur_max));
            }
            cur_min = elm;
            cur_max = elm;
        }   
    }
    return false;
}

// n == nums.length
// 1 <= n <= 2 * 10^5
// -10^9 <= nums[i] <= 10^9

void RunTestCases() {
    std::vector<int> input = {1,2,3,4};
    assert(find132pattern(input) == false);

    input = {3, 1, 4, 2};
    assert(find132pattern(input) == true);

    input = {-1, 3, 2, 0};
    assert(find132pattern(input) == true);

    input = {-1, 3, 3, 3};
    assert(find132pattern(input) == false);

    input = {100, 3, 2, 2};
    assert(find132pattern(input) == false);

    input = {1, 1, 1, 2, 2, 2};
    assert(find132pattern(input) == false);

    input = {1, 1, 2, 2, 3, 3, 3, 2};
    assert(find132pattern(input) == true);

    input = {1, 0, 1, -4, -3};
    assert(find132pattern(input) == false);

    input = {-1, 3, -5, -2, -10, -8, 0};
    assert(find132pattern(input) == true);
}

int main() {
    RunTestCases();
    return 0;
}