// LeetCode: 146. LRU Cache
// 146-LRU-Cache.cpp
// Created by Victor Rogulenko
// [2022-06-06 19:49]	

// Design a data structure that follows the constraints of a Least 
// Recently Used (LRU) cache.
// Implement the LRUCache class:
// LRUCache(int capacity) Initialize the LRU cache with positive 
// size capacity.
// int get(int key) Return the value of the key if the key exists, 
// otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. 
// Otherwise, add the key-value pair to the cache. If the number of keys exceeds 
// the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.

// 1 <= capacity <= 3000
// 0 <= key <= 10^4
// 0 <= value <= 10^5
// At most 2 * 10^5 calls will be made to get and put.

// MAJOR IDEA: Create a linked list with nodes (key, value, next, prev). 
// On every get operation, make the found node the head. On every put operation, 
// remove tail if necessary and make the updated node the head

const int MaxKey = 10010;

struct Node {
    int val;
    int key;
    Node* next;
    Node* prev;
    Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {};
};

class LRUCache {
public:
    LRUCache(int capacity) {
        size_ = capacity;
        for (int idx = 0; idx < MaxKey; ++idx) {
            cache[idx] = nullptr;
        }
    }
    
    int get(int key) {
        if (!cache[key]) {
            return -1;
        }
        if (cache[key] != head) {
            removeNode(cache[key]);
            makeHead(cache[key]);    
        }
        return cache[key]->val;
    }
    
    void put(int key, int value) {
        int isPresent = get(key);
        if (isPresent < 0 && used_ == size_) {
            cache[tail->key] = nullptr;
            removeNode(tail);            
            --used_;
        }
        if (isPresent >= 0) {
            head->val = value;
        } else {
            auto* new_node = new Node(key, value);
            makeHead(new_node);
            cache[key] = new_node;
            ++used_;
            if (!tail) {
                tail = new_node;
            }
        }
    }
    
private:
    void makeHead(Node* node) {
        node->prev = nullptr;
        node->next = head;
        if (head) {
            head->prev = node;
        }
        head = node;
    };
    
    void removeNode(Node* node) {
        if (node->prev) {
            node->prev->next = node->next;
        }
        if (node->next) {
            node->next->prev = node->prev;
        }
        if (node == tail) {
            tail = tail->prev;
        }  
    }
    
    int size_;
    int used_ = 0;
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* cache[MaxKey];
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// #bugs = 6