#include <iostream>
#include <limits>

const int MAXVAL = std::numeric_limits<int>::max();

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* readList() { // Reads size of the list, then reads nodes one by one
    int sz;
    std::cin >> sz;
    if (!sz) {
        return nullptr;
    }
    ListNode* result = new ListNode();
    ListNode* current_node = result;
    for (auto i = 0; i < sz; i++) {
        int node_data;
        std::cin >> node_data;
        current_node->val = node_data;
        if (i+1 < sz) {
            ListNode* new_node = new ListNode();
            current_node->next = new_node;
            current_node = new_node;
        }
    }
    return result;
}

void moveNode(ListNode*& list1, int& val) {
    if (list1 && (val == MAXVAL)) {
        val = list1->val;
        list1 = list1->next;
    }
}
 
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* result = nullptr;
    ListNode* current_node = result;
    int one = MAXVAL, two = MAXVAL;
    while (list1 || list2 || (one != MAXVAL) != (two != MAXVAL)) {
        ListNode* new_node = new ListNode();
        if (!result) {
            result = new_node;
        }
        if (current_node) {
            current_node->next = new_node;
        }
        current_node = new_node;
        moveNode(list1, one);
        moveNode(list2, two);
        current_node->val = (one < two ? one : two);
        if (one < two) {
            one = MAXVAL;
        } else {
            two = MAXVAL;
        }
    }
    return result;
}

void printList(ListNode* list1) {
    while (list1) {
        std::cout << list1->val << " ";
        list1 = list1->next;
    }
    std::cout << std::endl;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ListNode* one = readList();
    ListNode* two = readList();
    ListNode* result = mergeTwoLists(one, two);
    printList(result);
    // printList(one);
    // printList(two);
    return 0;
}