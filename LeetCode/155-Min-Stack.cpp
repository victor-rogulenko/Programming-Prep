// Created by Victor Rogulenko
// [2022-04-25 14:48]  

#include <iostream>

const int MAXINT = int(1e9);

struct StackNode {
    int val, minval;
    StackNode* next;

    StackNode() : val(MAXINT), minval(MAXINT), next(nullptr) {};
    
    StackNode(int new_value) : val(new_value), minval(new_value), next(nullptr) {};
    
    StackNode(int new_value, StackNode*& next_node) : val(new_value), minval(new_value), next(next_node) {
        if (next_node) {
            minval = (minval < next_node->minval ? minval : next_node->minval);
        }
    };
};

class MinStack {
public:
    MinStack() : top_node(nullptr) {};

    void push(int val) {
        StackNode* new_node = new StackNode(val, top_node);
        top_node = new_node;
    };
    
    void pop() {
        if (top_node) {
            StackNode* old_top = top_node;
            top_node = (top_node->next ? top_node->next : nullptr);
            delete old_top;
        }
    };
    
    int top() {
        return top_node->val;
    };
    
    int getMin() {
        return top_node->minval;
    };

private:
    StackNode* top_node;
};

int main() {
    MinStack* obj = new MinStack();
    obj->push(2);
    obj->push(2);
    obj->push(-1);
    obj->push(3);
    std::cout << "Current min is " << obj->getMin() << ", current top is " << obj->top() << std::endl;
    obj->pop();
    obj->pop();
    std::cout << "Current min is " << obj->getMin() << ", current top is " << obj->top() << std::endl;
    obj->push(-1000);
    std::cout << "Current min is " << obj->getMin() << ", current top is " << obj->top() << std::endl;
    return 0;
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */