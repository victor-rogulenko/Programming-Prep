// 88-Merge-Sorted-Array.cpp
// Created by Victor Rogulenko
// [2022-04-27 16:58]	

#include <vector>
#include <iostream>

template <class RandomAccessIterator>
RandomAccessIterator StepBack(RandomAccessIterator current,
	                          RandomAccessIterator begin_,
	                          RandomAccessIterator end_) {
	if (current == begin_) {
		return end_;
	} else {
		return --current;
	}
}

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    std::vector<int>::iterator paste_iterator = StepBack(nums1.end(), nums1.begin(), nums1.end());
    std::vector<int>::iterator copy_iterator_first = StepBack(nums1.begin() + m, nums1.begin(), nums1.end());
    std::vector<int>::iterator copy_iterator_second = StepBack(nums2.end(), nums2.begin(), nums2.end());
    while (paste_iterator != nums1.end()) {
    	if (((copy_iterator_first != nums1.end()) && (copy_iterator_second != nums2.end()) && 
    		(*copy_iterator_first > *copy_iterator_second)) ||
    		((copy_iterator_first != nums1.end()) && (copy_iterator_second == nums2.end()))) {

    		*paste_iterator = *copy_iterator_first;
    	    copy_iterator_first = StepBack(copy_iterator_first, nums1.begin(), nums1.end());
    	} else {
       		*paste_iterator = *copy_iterator_second;
    	    copy_iterator_second = StepBack(copy_iterator_second, nums2.begin(), nums2.end());
    	}
    	paste_iterator = StepBack(paste_iterator, nums1.begin(), nums1.end());
    }
}

std::vector<int> ReadVector(size_t len, std::istream& stream = std::cin) {
	std::vector<int> result(len);
	for (auto& element : result) {
		stream >> element;
	}
	return result;
}

void PrintVector(const std::vector<int>& result, std::ostream& stream = std::cout) {
	for (auto& element : result) {
		stream << element << " ";
	}
	stream << "\n";
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	size_t n, m;
	std::cin >> m >> n;
	std::vector<int> nums1 = ReadVector(m + n);
	std::vector<int> nums2 = ReadVector(n);
	merge(nums1, m, nums2, n);
	PrintVector(nums1);
	return 0;
}