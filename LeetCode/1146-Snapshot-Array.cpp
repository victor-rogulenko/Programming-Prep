// LeetCode: 1146. Snapshot Array
// 1146-Snapshot-Array.cpp
// Created by Victor Rogulenko
// [2022-08-04 15:29]

// Implement a SnapshotArray that supports the following interface:
// SnapshotArray(int length) initializes an array-like data structure with 
// the given length. Initially, each element equals 0.
// void set(index, val) sets the element at the given index to be equal to val.
// int snap() takes a snapshot of the array and returns the snap_id: the total 
// number of times we called snap() minus 1.
// int get(index, snap_id) returns the value at the given index, at the time 
// we took the snapshot with the given snap_id
// 1 <= length <= 5 * 10^4
// 0 <= index < length
// 0 <= val <= 10^9
// 0 <= snap_id < (the total number of times we call snap())
// At most 5 * 10^4 calls will be made to set, snap, and get.

#include <vector>
#include <algorithm> // std::lower_bound
#include <utility> // std::pair

class SnapshotArray {
public:
    SnapshotArray(int length) {
        std::vector<std::pair<int,int>> initVal(1, {-1, 0});
        storage.resize(length, initVal);
    }
    
    void set(int index, int val) {
        storage[index].push_back({snap_id, val});
    }
    
    int snap() {
        return ++snap_id;
    }
    
    int get(int index, int snap_id) {
        auto result = std::lower_bound(
            storage[index].begin(), storage[index].end(),
            std::make_pair(snap_id, 0));
        return (--result)->second;
    }
private:
    std::vector<std::vector<std::pair<int,int>>> storage;
    int snap_id = -1;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

// #bugs = 1