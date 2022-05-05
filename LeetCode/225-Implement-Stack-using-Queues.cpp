// LeetCode: 225. Implement Stack using Queues
// Created by Victor Rogulenko

#include <queue>
#include <cassert>

class MyStack {
public:
    MyStack() {};
    
    void push(int x) {
        if (!isEmpty) {
            main_queue->push(top_value);
        }
        isEmpty = false;
        top_value = x;
    };
    
    int pop() {
        assert (!isEmpty);
        int result = top_value;
        if (main_queue->size() == 0) {
            // popping top_value
            isEmpty = true;
        } else {
            std::queue<int>* temp = helper_queue;
            helper_queue = main_queue;
            main_queue = temp;
            while (helper_queue->size() > 1) {
                main_queue->push(helper_queue->front());
                helper_queue->pop();
            }
            top_value = helper_queue->front();
            helper_queue->pop();
        }
        return result;
    };
    
    int top() {
        assert (!isEmpty);
        return top_value;
    };
    
    bool empty() {
        return isEmpty;
    };

private:
    std::queue<int>* main_queue = new std::queue<int>();
    std::queue<int>* helper_queue = new std::queue<int>();
    int top_value = 0;
    bool isEmpty = true;
};

void RunTestCases() {
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    assert (obj->top() == 2);
    assert (obj->pop() == 2);
    assert (obj->empty() == false);
    assert (obj->pop() == 1);
    assert (obj->empty() == true);
}

int main() {
    RunTestCases();
    return 0;
}