// LeetCode: 4. Median of Two Sorted Arrays
// Created by Victor Rogulenko
// May 09, 2022

#include <cassert>
#include <vector>
#include <algorithm>
#include <limits> // numeric limits

const int MaxInt = std::numeric_limits<int>::max();
const int MinInt = std::numeric_limits<int>::min();

// The overall run time complexity should be O(log (m+n))

double findMedianSortedArrays(const std::vector<int>& nums1, 
                              const std::vector<int>& nums2) {
    int len1 = nums1.size(), len2 = nums2.size();
    // We need nums1 to be the smaller array. 
    // This avoids the overflow with mid1 and mid_combined_arrays
    if (len1 > len2) {
        return findMedianSortedArrays(nums2, nums1);
    }

    // We binsearch for the elements up to the median in nums1 (mid1)
    // The remaining elements up to median are in nums2 (mid2)
    int start = 0;
    int finish = len1;
    int mid_combined = (len1 + len2 + 1) / 2; // +1 takes care of parity

    while (start <= finish) {
        int mid1 = (start + finish) / 2;
        int mid2 = mid_combined - mid1;

        int L1 = (mid1 > 0    ? nums1[mid1 - 1] : MinInt);
        int R1 = (mid1 < len1 ? nums1[mid1]     : MaxInt);
        int L2 = (mid2 > 0    ? nums2[mid2 - 1] : MinInt);
        int R2 = (mid2 < len2 ? nums2[mid2]     : MaxInt);;

        // If the median is found:
        // L1 < R2, L2 < R1 - the 2 intervals intersect
        if ((L1 <= R2) && (L2 <= R1)) {
            if ((len1 + len2) % 2 == 0) {
                // Median is the average of 2 elements in the middle;
                return double(std::max(L1, L2) + std::min(R1, R2)) / 2;
            } else {
                // Median is just the middle element
                return std::max(L1, L2);
            }

        } else if (L1 > R2) {
            //  Get rid of the right segment of nums1: everything to the right of mid1
            //  and of the left segment of nums2
            finish = mid1 - 1;
        } else {
            // L2 > R1
            start = mid1 + 1;
        }
    }
    // We should never reach this return
    return MaxInt;
}

// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -10^6 <= nums1[i], nums2[i] <= 10^6

void RunTestCases() {
    std::vector<int> nums1{1, 3};
    std::vector<int> nums2{2};
    assert(findMedianSortedArrays(nums1, nums2) == 2);

    nums1 = {1, 2};
    nums2 = {3, 4};
    assert(findMedianSortedArrays(nums1, nums2) == 2.5);

    nums1 = {1};
    nums2 = {2, 4, 6, 8, 10, 12, 14};
    assert(findMedianSortedArrays(nums1, nums2) == 7);

    nums1 = {1, 3, 5, 7, 9};
    nums2 = {2, 4, 6, 8, 10, 12, 14, 16};
    assert(findMedianSortedArrays(nums1, nums2) == 7);

    nums1 = {1, 3, 5, 7, 9};
    nums2 = {12, 14, 16, 18, 20, 22, 24, 26};
    assert(findMedianSortedArrays(nums1, nums2) == 14);
}

int main() {
    RunTestCases();
    return 0;
}