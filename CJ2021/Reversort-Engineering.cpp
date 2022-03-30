#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define USE_STANDARD_IO true


vector<vector<int>> ReadTestCases (int T) {
    vector<vector<int>> result;
    int N = 0;
    int C = 0;

    for (int i = 0; i < T; i++) {
        cin >> N  >> C;
        result.push_back({N, C});
    }

    return result;
}

int ComputeTotalCost (vector<int> test_case) {
	int result = 0;

	for (auto it = begin(test_case); it < end(test_case)-1; it++) {
		auto left_it = it;
		auto right_it = min_element(it, end(test_case));
		result += distance(left_it, right_it + 1);
		reverse(left_it, right_it + 1);
	}

	return result;
}

vector<vector<int>> BuildAcceptableCosts() {
	// result[N][0] is min cost = N-1
	// result[N][1] is max cost = N*(N+1)/2 -1
	vector<vector<int>> result;
	result.push_back({0, 0}); // N = 0
	result.push_back({0, 0}); // N = 1

	int max_N = 101;
	for (auto N = 2; N < max_N; N++) {
        result.push_back({N-1, N*(N+1)/2 -1});    
	}

	return result;
}

vector<int> BuildMaxPermutation (int K) {
	int current_value = 2;
	vector<int> result;
	while (current_value <= K) {
		result.push_back(current_value);
		current_value += 2;
	}
	
	if (K % 2 == 0) {
        current_value = K-1;
	} else {
		current_value = K;
	}

    while (current_value > 0) {
    	result.push_back(current_value);
    	current_value -= 2;
    }

    return(result);
}

vector<int> FindPermutation (vector<int>& test_case, const vector<vector<int>>& acceptable_costs) {
    int N = test_case[0];
    int C = test_case[1];


    // if C is smaller than min cost or greater than max cost, quit
    if ((C > acceptable_costs[N][1]) | (C < acceptable_costs[N][0])) {
    	return (vector<int>{-1});
    }

    // find biggest K such that K(K+1)/2 + (N-K) < C
    int K = N;

    while ((K > 0) & (acceptable_costs[K][1] + N-K > C)) {
    	K--;
    }

    // build max permutation with K elements
    vector<int> result = BuildMaxPermutation(K);

    // insert element K+1 in the right place within the first K elements
    int extra_delta = C - acceptable_costs[K][1] - (N-K) + 1;
    // cout << endl;
    // cout << "acceptable_costs = " << acceptable_costs[K][1] << endl;
    // cout << "K = " << K << endl;
    // cout << "N = " << N << endl;
    // cout << "extra_delta = " << extra_delta << endl;
 
    if ((extra_delta > 0) & (K+1 <= N)) {
        int position_for_Kplus1 = 0;

        if (extra_delta % 2 == 1) {
    	    position_for_Kplus1 = K - extra_delta/2;
        } else {
    	    position_for_Kplus1 = extra_delta/2 - 1;
        }

        auto iterator_for_insertion = result.begin() + position_for_Kplus1;
        auto newIt = result.insert(iterator_for_insertion, K+1);
    }

    // add K+2, K+3, ..., N
    for (auto new_element = K+2; new_element < N+1; new_element++) {
  	    result.push_back(new_element);
    }

    return result;
}

void PrintPermutation (int case_number, const vector<int>& permutation) {
	cout << "Case #" << case_number + 1 << ": ";
	if (permutation[0] == -1) {
		cout << "IMPOSSIBLE";
	} else {
		for (auto it = begin(permutation); it < end(permutation); it++) {
			cout << *it << " ";
		}
	}
	cout << endl;
}

int main() {
    
    #ifndef USE_STANDARD_IO
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
	#endif
	
    vector<vector<int>> acceptable_costs = BuildAcceptableCosts();

    int T = 0;
    cin >> T;

    vector<vector<int>> test_cases = ReadTestCases(T);

    for (int i = 0; i < T; i++) {
    	vector<int> result = FindPermutation(test_cases[i], acceptable_costs);
    	// int cost = ComputeTotalCost(result);
    	// if ((result[0] != -1) & (cost != test_cases[i][1])) {
    	//     cout << "ERROR: expected cost is " << test_cases[i][1] << ", but actual cost is " << cost << endl;
    	// }
    	PrintPermutation (i, result);
    }

	return 0;
}