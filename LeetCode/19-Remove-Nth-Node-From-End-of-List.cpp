// LeetCode: 19. Remove Nth Node From End of List
// 19-Remove-Nth-Node-From-End-of-List.cpp

ListNode* removeNthFromEnd(ListNode* root, int num_to_be_deleted) {
    if (root->next == nullptr) {
    	delete root;
    	return nullptr;
    }
    auto ptr_right = root;
    int cnt = 0;
    while (ptr_right != nullptr && cnt <= num_to_be_deleted) {
        ++cnt;
        ptr_right = ptr_right->next;
    }
    if (cnt <= num_to_be_deleted) {
    	auto new_root = root->next;
    	delete root;
    	return new_root;
    }
    auto ptr_left = root;
    while (ptr_right != nullptr) {
        ptr_left = ptr_left->next;
        ptr_right = ptr_right->next;
    }
    auto parent = ptr_left;
    auto to_be_deleted = ptr_left->next;
    auto child = ptr_left->next->next;
    
    parent->next = child;
    if (to_be_deleted != nullptr) {
        delete to_be_deleted;   
    }
    
    return root;
}