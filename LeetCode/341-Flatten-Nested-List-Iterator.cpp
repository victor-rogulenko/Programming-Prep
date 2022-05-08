// LeetCode: 341. Flatten Nested List Iterator
// Created by Victor Rogulenko
// May 08, 2022

#include <cassert>
#include <vector>

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const std::vector<NestedInteger> &getList() const;
};


 /**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

class NestedIterator {
public:
    void flatten(NestedInteger& elm) {
        if (elm.isInteger()) {
            result.push_back(elm.getInteger());
        } else {
            std::vector<NestedInteger> children = elm.getList();
            for (auto child : children) {
                flatten(child);
            }
        }
    }

    NestedIterator(std::vector<NestedInteger> nestedList) {
        for (auto child : nestedList) {
            flatten(child);
        }
        cur_it = 0;
    };
    
    int next() {
        return result[cur_it++];
    }
    
    bool hasNext() {
        return cur_it < result.size();
    }

private:
    std::vector<int> result;
    int cur_it;
};

// 1 <= nestedList.length <= 500
// The values of the integers in the nested list is in the range [-10^6, 10^6]

// void RunTestCases() {
//     assert(TBD() == "");
// }

int main() {
    // RunTestCases();
    return 0;
}