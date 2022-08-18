// LeetCode: 1825. Finding MK Average
// 1825-Finding-MK-Average.cpp

// You are given two integers, m and k, and a stream of integers. 
// You are tasked to implement a data structure that calculates 
// the MKAverage for the stream.
// The MKAverage can be calculated using these steps:
// - If the number of the elements in the stream is less than m you 
// should consider the MKAverage to be -1. Otherwise, copy the last 
// m elements of the stream to a separate container.
// - Remove the smallest k elements and the largest k elements from 
// the container.
// - Calculate the average value for the rest of the elements rounded 
// down to the nearest integer.
// Implement the MKAverage class:
// - MKAverage(int m, int k) Initializes the MKAverage object with 
// an empty stream and the two integers m and k.
// - void addElement(int num) Inserts a new element num into the stream.
// - int calculateMKAverage() Calculates and returns the MKAverage for 
// the current stream rounded down to the nearest integer.
// 3 <= m <= 10^5
// 1 <= k*2 < m
// 1 <= num <= 10^5
// At most 10^5 calls will be made to addElement and calculateMKAverage.

// MAJOR IDEA: Store the stream in a queue. Keep 3 multisets: minHeap, 
// maxHeap, and midHeap. Remove old elements from the heaps, adjust midHeap 
// and sum of midHeap accordingly. Add new element to maxHeap. 
// If it gets too big, move its smallest element to minHeap. 
// If the latter gets too big too, move its bigges element to midHeap and 
// adjust the sum
// Time: O(M log N). Space: O(N). N - number of add queries, 
// M - number of calc queries

#include <multiset>
#include <queue>

class MKAverage {
public:
    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
        sum = 0;
        cnt = 0;
    }
    
    void addElement(int num) {
        ++cnt;
        q.push(num);
        
        // Remove the oldest element
        if (cnt > m) {
            int oldNum = q.front();
            q.pop();
            auto oldNumMaxHeap = maxHeap.find(oldNum);
            auto oldNumMinHeap = minHeap.find(oldNum);
            
            if (oldNumMaxHeap != maxHeap.end()) {
                maxHeap.erase(oldNumMaxHeap);
                int elm = *midHeap.begin();
                midHeap.erase(midHeap.begin());
                sum -= elm;
                maxHeap.insert(elm);
                
            } else if (oldNumMinHeap != minHeap.end()) {
                minHeap.erase(oldNumMinHeap);
                int elm = *midHeap.rbegin();
                midHeap.erase(midHeap.find(elm));
                sum -= elm;
                minHeap.insert(elm);
                
            } else {
                midHeap.erase(midHeap.find(oldNum));
                sum -= oldNum;
            }
        }
        
        // Add the new element to the heaps
        maxHeap.insert(num);
        if (maxHeap.size() > k) {
            int elm = *maxHeap.rbegin();
            maxHeap.erase(maxHeap.find(elm));
            minHeap.insert(elm);
            if (minHeap.size() > k) {
                int elm2 = *minHeap.begin();
                minHeap.erase(minHeap.begin());
                sum += elm2;
                midHeap.insert(elm2);
            }
        }
    }
    
    int calculateMKAverage() {
        return (cnt < m ? -1 : sum / (m - 2*k));
    }

private:
    std::multiset<int> maxHeap, minHeap, midHeap;
    std::queue<int> q;
    long sum;
    int cnt, m, k;
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */