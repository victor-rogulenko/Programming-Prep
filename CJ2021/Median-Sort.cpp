#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <string>

using namespace std;

enum InquiryResult {LESS, GREATER, MEDIAN};


InquiryResult MakeInquiry(int left, int right, int candidate) {

    cout << left << " " << right << " " << candidate << endl;

    InquiryResult result = MEDIAN;

    int judge_reply;
    cin >> judge_reply;

    if (judge_reply == -1) {
        throw exception();
    } else if (judge_reply == left) {
        result = LESS;
        //cout << "LESS " << endl;
    } else if (judge_reply == right) {
        result = GREATER;
        //cout << "GREATER " << endl;
    } //else {
      //  cout << "MEDIAN " << endl;
    //}

    return result;
}

void PrintVector(const vector<int>& v) {
    for (auto it : v) {
        cout << it << " ";
    }
    cout << endl;
}

void PlaceNewIndex(vector<int>& sorted, vector<int>::iterator left_border, 
                   vector<int>::iterator right_border, int new_index) {
    
    int subvector_size = right_border - left_border;

    // cout << "cheking " << *left_border << " and " << *right_border << endl;
    // cout << "subvector_size = " << subvector_size << endl;
    // PrintVector(sorted);

    if (subvector_size < 0) {
        sorted.insert(left_border, new_index);

    } else if (subvector_size == 0) {
        // we are pointing at one element
        if (left_border != sorted.begin()) {
            PlaceNewIndex(sorted, left_border-1, right_border, new_index);
        } else {
            PlaceNewIndex(sorted, left_border, right_border+1, new_index);
        }

    } else if (subvector_size < 4) {
        // 2, 3 or 4 elements
        InquiryResult inquiry_result = MakeInquiry(*left_border, *(left_border+1), new_index);
        // cout << "flag1" << endl;
        if (inquiry_result == LESS) {
            // cout << "flag2" << endl;
            sorted.insert(left_border, new_index);
        } else if (inquiry_result == MEDIAN) {
            // cout << "flag3" << endl;
            sorted.insert(left_border+1, new_index);
        } else {
            // cout << "flag4" << endl;
            if (subvector_size == 1) {
                sorted.insert(left_border+2, new_index);
            } else {
                PlaceNewIndex(sorted, right_border-1, right_border, new_index);
            }
        }

    } else if (subvector_size == 4) {
        // 5 elements
        InquiryResult inquiry_result = MakeInquiry(*(left_border+2), *(left_border+3), new_index);
        if (inquiry_result == LESS) {
            PlaceNewIndex(sorted, left_border, left_border+1, new_index);
        } else if (inquiry_result == MEDIAN) {
            sorted.insert(left_border+3, new_index);
        } else {
            PlaceNewIndex(sorted, right_border-1, right_border, new_index);
        }

    } else {
        // 6 elements or more
        vector<int>::iterator mid_left_border = sorted.begin() + (subvector_size+1)/3;
        vector<int>::iterator mid_right_border = sorted.begin() + 2*(subvector_size+1)/3 -1;

        InquiryResult inquiry_result = MakeInquiry(*(mid_left_border), *(mid_right_border), new_index);
        if (inquiry_result == LESS) {
            PlaceNewIndex(sorted, left_border, mid_left_border-1, new_index);
        } else if (inquiry_result == MEDIAN) {
            PlaceNewIndex(sorted, mid_left_border+1, mid_right_border-1, new_index);
        } else {
            PlaceNewIndex(sorted, mid_right_border+1, right_border, new_index);
        }
    }
}

void CheckJudgement() {
    int result;
    cin >> result;
    if (result == 1) {
        return;
    } else {
        throw exception();
    }
}

void Solve(int N) {
    vector<int> sorted = {1, 2};

    int new_index = 3;

    while (new_index <= N) {
        PlaceNewIndex(sorted, sorted.begin(), sorted.end()-1, new_index);
        new_index++;
    }

    PrintVector(sorted);
    CheckJudgement();
}

int main() {
	
    int T = 0;
    int N = 0;
    int Q = 0;

    cin >> T >> N >> Q;

    for (int i = 0; i < T; i++) {
    	try {
            Solve(N);
        } catch (const exception& e) {
            return(0);
        }
    }

	return 0;
}