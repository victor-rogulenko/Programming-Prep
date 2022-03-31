#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define INF 1500000000

#define USE_STANDARD_IO true

struct TestCase {
	// C is 0 and J is 1
	// ? is 2
	// X is price of CJ, i.e. Price01
	// Y is price of JC, i.e. Price10
	int Price01;
	int Price10;
	vector<int> Mural;
};

vector<TestCase> ReadTestCases (int T) {
    vector<TestCase> result;

    for (int i = 0; i < T; i++) {
        TestCase current_test_case;
        string mural_string;

        cin >> current_test_case.Price01 >> current_test_case.Price10;
        cin >> mural_string;

        for (auto& it : mural_string) {
        	if (it == 'C') {
        		current_test_case.Mural.push_back(0);
        	} else if (it == 'J') {
        		current_test_case.Mural.push_back(1);
        	} else {
        		current_test_case.Mural.push_back(2);
        	}
        }

        result.push_back(current_test_case);
    }

    return result;
}

int FindMinMuralCost(const TestCase& test_case) {
	int result = 0;
	vector<int> v(test_case.Mural.size(), INF);
	vector<vector<int>> min_cost(2, v);

	//cout << "len of mural = " << test_case.Mural.size() << endl;

	if (test_case.Mural[0] != 1) { // 0 or 2, i.e. C or ?
		min_cost[0][0] = 0;
	}
	if (test_case.Mural[0] != 0) { // 1 or 2, i.e. J or ?
		min_cost[1][0] = 0;
	}

	int index = 1;
	for (auto it = test_case.Mural.begin()+1; it < test_case.Mural.end(); it++) {
		//cout << index << " " << *it << endl;

		if (*it == 0) { // current value is 0 (C), so it cannot be 1 (J)
			min_cost[1][index] = INF;
		} else {  // current value can be 1 (J)
			min_cost[1][index] = min(min_cost[0][index-1] + test_case.Price01, min_cost[1][index-1]);
		}

		if (*it == 1) { // current value is 1 (J), so it cannot be 0 (C)
			min_cost[0][index] = INF;
		} else {  // current value can be 0 (C)
			min_cost[0][index] = min(min_cost[0][index-1], min_cost[1][index-1] + test_case.Price10);
		}

		//cout << min_cost[0][index] << " " << min_cost[1][index] << endl;

        index++;
	}
	index--;

	return min(min_cost[0][index], min_cost[1][index]);
}

void PrintAnswerToCase (const int case_number, const int answer) {
	cout << "Case #" << case_number+1 << ": " << answer << endl;
}

int main() {
    
    #ifndef USE_STANDARD_IO
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
	#endif
	
    int T = 0;
    cin >> T;

    vector<TestCase> test_cases = ReadTestCases(T);

    for (int i = 0; i < T; i++) {
    	int current_cost = FindMinMuralCost(test_cases[i]);
    	PrintAnswerToCase (i, current_cost);
    }

	return 0;
}

