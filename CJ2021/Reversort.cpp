#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define USE_STANDARD_IO true


vector<vector<int>> ReadTestCases (int T) {
    vector<vector<int>> result;

    for (int i = 0; i < T; i++) {
        int N = 0;
        cin >> N;
        vector<int> current_case(N);
        for (int j = 0; j < N; j++) {
        	cin >> current_case[j];
        }
        result.push_back(current_case);
    }

    return result;
}

template<class ForwardIt>
void PrintVector(ForwardIt first, ForwardIt last) {
	for (auto it = first; it < last; it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int ComputeTotalCost (vector<int>& test_case) {
	int result = 0;

	for (auto it = begin(test_case); it < end(test_case)-1; it++) {
		auto left_it = it;
		auto right_it = min_element(it, end(test_case));
		result += distance(left_it, right_it + 1);
		reverse(left_it, right_it + 1);
	}

	return result;
}

void PrintCost (int case_number, int total_cost) {
	cout << "Case #" << case_number + 1 << ": " << total_cost << endl;
}

int main() {
    
    #ifndef USE_STANDARD_IO
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
	#endif
	
    int T = 0;
    cin >> T;

    vector<vector<int>> test_cases = ReadTestCases(T);

    for (int i = 0; i < T; i++) {
    	int total_cost = ComputeTotalCost(test_cases[i]);
    	PrintCost (i, total_cost);
    }

	return 0;
}