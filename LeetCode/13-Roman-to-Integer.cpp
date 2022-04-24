// Created by Victor Rogulenko
// Date and time: [2022-04-24 17:28]

#include <iostream>
#include <map>
#include <string>

using namespace std;

int casenum = 1;
const int maxdigit = int(1e6);
std::map<char, int> roman_digits { {'I', 1}, 
                             {'V', 5}, 
                             {'X', 10}, 
                             {'L', 50}, 
                             {'C', 100}, 
                             {'D', 500}, 
                             {'M', 1000}}; 

//Uncomment to use standard input/output:
//#define USE_STANDARD_IO true

int MakeIntegerFromRoman(string& roman_number) {
	int cur = 0;
	int previous_digit = maxdigit;
	int result = 0;
	while (cur < roman_number.size()) {
		int current_digit = roman_digits[roman_number[cur]];
		if (previous_digit < current_digit) {
			result -= previous_digit*2;
		}
		result += current_digit;
		previous_digit = current_digit;
		cur++;
	}
	return result;
}

void solve() {
	string roman_number;
	cin >> roman_number;
	int res = MakeIntegerFromRoman(roman_number);
	cout << "Case #" << casenum << ": " << res << endl;
	casenum++;
}

int main() {
	#ifndef USE_STANDARD_IO
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int T;
    cin >> T;
    while (T--) solve();
	return 0;
}