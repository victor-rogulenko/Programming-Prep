// 1796. Second Largest Digit in a String
// Created by Victor Rogulenko

#include <string>
#include <cassert>

int secondHighest(std::string s) {
    int result = -1;
    int max_digit = -1;
    for (auto& ch : s) {
        int converted_digit = (int)(ch) - (int)('0');
        if ((converted_digit < 0) || (converted_digit > 9)) {
            continue;
        }
        if (converted_digit > max_digit) {
            result = max_digit;
            max_digit = converted_digit;
        } else if ((converted_digit < max_digit) && (converted_digit > result)) {
            result = converted_digit;
        }
    }
    return result;    
}

void RunTestCases() {
    assert (secondHighest("dfa12321afd") == 2);
    assert (secondHighest("abc1111") == -1);
    assert (secondHighest("abcasd1sdfasfas2adsfsasd") == 1);
    assert (secondHighest("sdfsaf0asdfsfa0sdfasf") == -1);
    assert (secondHighest("sdfsaf0asdfsfa1sdfasf") == 0);
    assert (secondHighest("sdfsaf9asdfsfa1sdfasf") == 1);
    assert (secondHighest("1") == -1);
    assert (secondHighest("z") == -1);
}

int main() {
    RunTestCases();
    return 0;
}