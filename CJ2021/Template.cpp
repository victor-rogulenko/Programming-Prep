#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//#define USE_STANDARD_IO true

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


int main() {
    
    #ifndef USE_STANDARD_IO
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
	#endif
	
    int T = 0;
    cin >> T;

    vector<vector<int>> test_cases = ReadTestCases(T);

    for (int i = 0; i < T; i++) {
    	/// solve
    }

	return 0;
}