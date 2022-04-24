// Created by Victor Rogulenko
// [2022-04-24 18:38]	

#include <iostream>
#include <map>
#include <stack>
#include <string>

int casenum = 1;
const std::map<char, int> bracket_to_int { {'(', 0},
                                {')', 1},
                                {'[', 2},
                                {']', 3},
                                {'{', 4},
                                {'}', 5} };

bool isValid(std::string s) {
	std::stack<int> st;
	for (auto& ch : s) {
		// if the symbol is not a bracket, return false
		if (bracket_to_int.find(ch) == bracket_to_int.end()) {
			return false;
		}
		int cur = bracket_to_int.at(ch);
		// if the symbol is a closing bracket
		if (cur & 1) {
			// if there are no opening brackets, return false
			if (st.empty()) {
				return false;
			}
			int prev = st.top();
			// if the previous bracket does not match the current one, return false
			if ((cur >> 1) != (prev >> 1)) {
				return false;
			} else {
				// close the previous bracket with the current one
				st.pop();
			}
		} else {
			// add the opening bracket to the stack
			st.push(cur);
		}
	}
	return (st.empty());
}

void solve() {
	std::string input;
	std::cin >> input;
	bool result = isValid(input);
	std::cout << "Case #" << casenum << ": " << result << std::endl;
	casenum++;
}


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	std::cin >> T;
	while (T--) solve();
	return 0;
}
