// Created by Victor Rogulenko
// [2022-04-24 19:30]	

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* makeNumber(int num) {
	ListNode* start = new ListNode();
	ListNode* current_node = start;
	do {
		int current_digit = num % 10;
		current_node->val = current_digit;
		if (num > 9) {
			ListNode* new_node = new ListNode();
			current_node->next = new_node;
		    current_node = new_node;
		}
		num /= 10;
	} while (num > 0);
	return start;
}

void printList(ListNode* l1) {
	while (l1 != nullptr) {
		std::cout << l1->val;
		l1 = l1->next;
	}
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* start = new ListNode();
	ListNode* current_node = start;
	int add_digit = 0;
	while (l1 || l2 || add_digit) {
		int one = (l1 != nullptr ? l1->val : 0);
		int two = (l2 != nullptr ? l2->val : 0);
		int new_digit = one + two + add_digit;
		current_node->val = new_digit % 10;
		add_digit = new_digit / 10;
		
		if (l1 != nullptr) l1 = l1->next;
		if (l2 != nullptr) l2 = l2->next;
		if (l1 || l2 || add_digit) {
			ListNode* new_node = new ListNode();
			current_node->next = new_node;
			current_node = new_node;
		}
	}

	return start;
}
 
int main() {
	int number_one, number_two;
	std::cin >> number_one >> number_two;
	printList(addTwoNumbers(makeNumber(number_one), makeNumber(number_two)));
	return 0;
}