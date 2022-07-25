// LeetCode: 2034. Stock Price Fluctuation
// 2034-Stock-Price-Fluctuation.cpp
// Created by Victor Rogulenko
// [2022-07-25 17:00]

// You are given a stream of records about a particular stock. Each record contains a timestamp 
// and the corresponding price of the stock at that timestamp.
// Unfortunately due to the volatile nature of the stock market, the records do not come 
// in order. Even worse, some records may be incorrect. Another record with the same 
// timestamp may appear later in the stream correcting the price of the previous wrong record.
// Design an algorithm that:
// - Updates the price of the stock at a particular timestamp, correcting the price 
// from any previous records at the timestamp.
// - Finds the latest price of the stock based on the current records. The latest price 
// is the price at the latest timestamp recorded.
// - Finds the maximum price the stock has been based on the current records.
// - Finds the minimum price the stock has been based on the current records.
// Implement the StockPrice class:
// - StockPrice() Initializes the object with no price records.
// - void update(int timestamp, int price) Updates the price of the stock at the given timestamp.
// - int current() Returns the latest price of the stock.
// - int maximum() Returns the maximum price of the stock.
// - int minimum() Returns the minimum price of the stock.

// 1 <= timestamp, price <= 10^9
// At most 10^5 calls will be made in total to update, current, maximum, and minimum.
// current, maximum, and minimum will be called only after update has been called at least once.

// MAJOR IDEA 1. Heaps minHeap and maxHeap of pairs(price, timestamp) and hash table timestampPrice. 
// Time O(NlogN), memory O(N) 
// MAJOR IDEA 2. Hash table priceFrequencies and hash table timestampPrice. 
// Time O(NlogN), memory O(N)

// Solution 1. Heaps

#include <unordered_map>
#include <utility> // std::pair
#include <priority_queue>

class StockPrice {
public:
    StockPrice() { 
    }
    
    void update(int timestamp, int price) {
        mp[timestamp] = price;
        maxHeap.push(std::make_pair(price, timestamp));
        minHeap.push(std::make_pair(price, timestamp));
        
        if (latestTimestamp <= timestamp) {
            latestTimestamp = timestamp;
            latestPrice = price;
        }
    }
    
    int current() {
       return latestPrice; 
    }
    
    int maximum() {
        while (mp[maxHeap.top().second] != maxHeap.top().first) {
            maxHeap.pop();
        }
        return maxHeap.top().first;        
    }
    
    int minimum() {
        while (mp[minHeap.top().second] != minHeap.top().first) {
            minHeap.pop();
        }
        return minHeap.top().first;  
    }
    
private:
    int latestTimestamp = 0, latestPrice = 0;
    std::unordered_map<int,int> mp;
    std::priority_queue<std::pair<int,int>> maxHeap;
    std::priority_queue<std::pair<int,int>, 
                        std::vector<std::pair<int,int>>, 
                        greater<std::pair<int,int>>> minHeap;
};

// #bugs = 3

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */