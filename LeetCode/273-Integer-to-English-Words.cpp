// LeetCode: 273. Integer to English Words
// 273-Integer-to-English-Words.cpp
// Created by Victor Rogulenko
// [2022-06-06 20:42]  

// Convert a non-negative integer num to its English words representation.
// 0 <= num <= 2^31 - 1

// MAJOR IDEA: Create const arrays of number names. Serialize num into triplets. 
// Parse each triplet individually. Careful with corner cases (zero, spaces)

#include <vector>
#include <string>

const std::vector<std::string> units = {"Zero", "One", "Two", "Three", "Four", "Five",
                                       "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
                                       "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                                       "Seventeen", "Eighteen", "Nineteen"};

const std::vector<std::string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty",
                                      "Seventy", "Eighty", "Ninety"};

const std::vector<std::string> powers = {"", "Thousand", "Million", "Billion"};

class Solution {
public:
    std::string numberToWords(int num) {
        if (num == 0) {
            return units[0];
        }
        std::vector<int> triplets = serialize(num);
        int cur = triplets.size() - 1;
        int last_nonzero = 0;
        while (triplets[last_nonzero] == 0) {
            ++last_nonzero;
        }
        
        std::string result = "";
        
        while (cur >= last_nonzero) {
            if (triplets[cur] > 0) {
                result += " " + parseThousand(triplets[cur]);
                result += " " + powers[cur];
            }
            --cur;
        }
        if (result.back() == ' ') {
            result.pop_back();
        }
        if (result[0] == ' ') {
            result.erase(0, 1);
        }
        return result;
    };
    
private:
    std::string parseThousand(int num) {
        std::string result = "";
        if (num > 99) {
            result += units[num/100] + " " + "Hundred";
        }
        num %= 100;
        if (num > 19) {
            if (result.length() > 0) {
                result += " ";
            }
            result += tens[num/10];
            num %= 10;
        }
        if (num > 0) {
            if (result.length() > 0) {
                result += " ";
            }
            result += units[num];
        }
            
        return result;
    }
    
    std::vector<int> serialize(int num) {
        std::vector<int> result;
        while (num > 0) {
            result.push_back(num % 1000);
            num /= 1000;
        }
        return result;
    }   
};

// #bugs = 2;