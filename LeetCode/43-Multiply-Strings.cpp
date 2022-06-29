// LeetCode: 43. Multiply Strings
// 43-Multiply-Strings.cpp
// Created by Victor Rogulenko
// June 29, 2022
// Given two non-negative integers num1 and num2 represented as strings, 
// return the product of num1 and num2, also represented as a string.
// Note: You must not use any built-in BigInteger library or convert 
// the inputs to integer directly.
// 1 <= num1.length, num2.length <= 200
// num1 and num2 consist of digits only.
// Both num1 and num2 do not contain any leading zero, except the number 0 itself.

// MAJOR IDEA: Reverse strings. Write carry into result[idx + jdx + 1] += (multiple / 10)

#include <string>

// SOLUTION 1. Shorter, more elevant

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        
        int len1 = num1.length();
        int len2 = num2.length();
        
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        
        std::string result(len1 + len2, '0');
        
        for (int idx = 0; idx < len1; ++idx) {
            int digit1 = num1[idx] - '0';
            
            for (int jdx = 0; jdx < len2; ++jdx) {
                int digit2 = num2[jdx] - '0';
                int carry = result[idx + jdx] - '0';
                
                int multiple = digit1 * digit2 + carry;
                result[idx + jdx] = (multiple % 10) + '0';
                result[idx + jdx + 1] += (multiple / 10);
            }
        }
        
        if (result.back() == '0') {
            result.pop_back();
        }
        
        std::reverse(result.begin(), result.end());
        return result;
    };
};

// SOLUTION 2. Longer

class Solution2 {
public:
    std::string multiply(const std::string& num1, const std::string& num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        
        std::string longer_string = std::string(num1.rbegin(), num1.rend());
        std::string shorter_string = std::string(num2.rbegin(), num2.rend());
                
        if (longer_string.length() < shorter_string.length()) {
            std::swap(longer_string, shorter_string);
        }
        
        std::string result;
        for (int idx = 0; idx < shorter_string.length(); ++idx) {
            int cur_int = (int)(shorter_string[idx]) - (int)('0');
            std::string candidate = multiplyReverseStringInt(longer_string, cur_int, idx);
            result = addReverse(result, candidate);
        }
        
        return std::string(result.rbegin(), result.rend());
    };
    
private:
    std::string multiplyReverseStringInt(const std::string& str, int multiplier, int offset) {
        if (multiplier == 0) {
            return "0";
        }
        
        std::string result;
        while (offset > 0) {
            result += '0';
            --offset;
        }
        
        int extra = 0;
        int idx = 0;
        while (idx < str.length() || extra > 0) {
            int new_int = extra;
            if (idx < str.length()) {
                new_int += multiplier * ((int)(str[idx]) - (int)('0'));
                ++idx;
            }
            result += (char)(new_int % 10 + (int)('0'));
            extra = new_int / 10;
        }
        
        return result;
    }
    
    std::string addReverse(const std::string& str1, const std::string& str2) {
        std::string result;
        int extra = 0;
        int idx = 0;
        while (idx < str1.length() || idx < str2.length() || extra > 0) {
            int new_int = extra;
            if (idx < str1.length()) {
                new_int += (int)(str1[idx]) - (int)('0');
            }
            if (idx < str2.length()) {
                new_int += (int)(str2[idx] - (int)('0'));
            }
            ++idx;
            result += (char)(new_int % 10 + (int)('0'));
            extra = new_int / 10;
        }
        
        return result;
    }
};

// #bugs = 1