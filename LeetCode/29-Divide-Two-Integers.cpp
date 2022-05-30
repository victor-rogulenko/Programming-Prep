// LeetCode: 29. Divide Two Integers
// 29-Divide-Two-Integers.cpp
// Created by Victor Rogulenko
// [2022-05-30 13:30]	

// Given two integers dividend and divisor, divide two integers without 
// using multiplication, division, and mod operator.
// The integer division should truncate toward zero, which means 
// losing its fractional part. For example, 8.345 would be truncated to 8, 
// and -2.7335 would be truncated to -2.
// Return the quotient after dividing dividend by divisor.
// Note: Assume we are dealing with an environment that could only store 
// integers within the 32-bit signed integer range: [−2^31, 2^31 − 1]. 
// For this problem, if the quotient is strictly greater than 231 - 1, 
// then return 2^31 - 1, and if the quotient is strictly less than -2^31, 
// then return -2^31.

// -2^31 <= dividend, divisor <= 2^31 - 1
// divisor != 0

// MAJOR IDEA: Cast to unsigned to avoid overflow
// int pow = findMaxPow(dividend, divisor);   
// result += (1 << pow);    dividend += (divisor << pow);

const int MaxInt = std::numeric_limits<int>::max();

class Solution {
public:
    unsigned findMaxPow(unsigned dividend, 
                        unsigned divisor) {
        unsigned result = 0;
        while ((result < 32) && 
               (dividend > (divisor << result))) {
            ++result;
        }
        if ((result > 0) && (dividend < (divisor << result))) {
            --result;
        }
        return result;
    }
    
    int divide(int dividend, int divisor) {
        unsigned result = 0;
        
        int sign = ((1 << 31) & divisor) ^ ((1 << 31) & dividend);
        unsigned divisor_unsigned = std::abs(divisor);
        unsigned dividend_unsigned = std::abs(dividend);
        
        while (dividend_unsigned >= divisor_unsigned) {
            unsigned pow = findMaxPow(dividend_unsigned, divisor_unsigned);
            result += (1 << pow);
            dividend_unsigned -= (divisor_unsigned << pow);
        }
        
        return (sign != 0 ? -result : 
                            std::min((unsigned)(MaxInt), result));
    }
};

// 10 = 1010(2) -> 4 -> 1
// 3 = 11(2)

// pow = 1
// res = 2^1 + 2^0

// #bugs = 8