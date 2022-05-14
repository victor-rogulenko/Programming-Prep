// LeetCode: 2271. Maximum White Tiles Covered by a Carpet
// 78-2271-Maximum-White-Tiles-Covered-by-a-Carpet.cpp
// Created by Victor Rogulenko
// May 14, 2022

// You are given a 2D integer array tiles where tiles[i] = [li, ri] 
// represents that every tile j in the range li <= j <= ri is colored white.
// You are also given an integer carpetLen, the length of a single 
// carpet that can be placed anywhere.
// Return the maximum number of white tiles that can be covered by the carpet.

// 1 <= tiles.length <= 5 * 10^4
// tiles[i].length == 2
// 1 <= li <= ri <= 10^9
// 1 <= carpetLen <= 10^9
// The tiles are non-overlapping.

#include <cassert>
#include <string>
#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumWhiteTiles(std::vector<std::vector<int>>& tiles, int carpetLen) {
        int result = 0;

        // sort the tiles by the l values
        std::sort(tiles.begin(), tiles.end(), 
                  [](std::vector<int>& lhs, std::vector<int>& rhs){
                        return lhs[0] < rhs[0];
                  });

        // Initiate the carpet
        int idx_finish = 0;
        int cnt = 0;

        // Iterate over all tiles and move the carpet accordingly
        for (int idx_start = 0; idx_start < tiles.size(); ++idx_start) {
            // std::cout << "tiles[idx_start][0] = " << tiles[idx_start][0] << "\n";

            idx_finish = (idx_start > idx_finish ? idx_start : idx_finish);

            while ((idx_finish < tiles.size()) && 
               (tiles[idx_start][0] + carpetLen - 1) >= tiles[idx_finish][1]) {
                // std::cout << "tiles[idx_finish][1] = " << tiles[idx_finish][1] << "\n";
                cnt += (tiles[idx_finish][1] - tiles[idx_finish][0] + 1);
                ++idx_finish;
            }
            int diff = 0;
            if ((idx_finish < tiles.size()) && 
                (tiles[idx_start][0] + carpetLen - 1 >= tiles[idx_finish][0])){
                diff = (tiles[idx_start][0] + carpetLen - 1) - tiles[idx_finish][0] + 1;
                cnt += diff;

            }
            // std::cout << "cnt = " << cnt << "\n\n";

            result = (result < cnt ? cnt : result);

            // Moving the head forward, so the prev tile is not covered anymore;
            cnt -= (tiles[idx_start][1] - tiles[idx_start][0] + 1);
            cnt -= diff;
        }

        // return result
        return result;
    }
};

void TestCase(std::vector<std::vector<int>> input, int carpetLen, int expected) {
    int result = Solution().maximumWhiteTiles(input, carpetLen);
    std::cout << "result = " << result << ", expected = " << expected << "\n";
    assert(result == expected);
}

void RunTestCases() {
    TestCase(std::vector<std::vector<int>>{{1,5},{10,11},{12,18},{20,25},{30,32}}, 10, 9);
    TestCase(std::vector<std::vector<int>>{{10,11},{1,1}}, 2, 2);
    TestCase(std::vector<std::vector<int>>{{1,5}}, 2, 2);
}

int main() {
    RunTestCases();
    return 0;
}