/*
	1. Two Sum (EASY)
	Given an array of integers, return indices of the two numbers such that they add up to a specific target.
	You may assume that each input would have exactly one solution, and you may not use the same element twice.
    Input:
        nums = [2, 7, 11, 15], target = 9
    Output:
        [0, 1]
    Because nums[0] + nums[1] = 2 + 7 = 9
*/


// Includes all standard library (ONLY for GCC, not standard C++ library)
#include <bits/stdc++.h>

using namespace std;

/*
 * Class to perform 'Two Sum' implementation
 */
class TwoSumSolution {
public:

	// Method to implement 'Two Sum'
    vector<int> twoSum(vector<int>& nums, int target) {
    	// Corner Case
    	if (nums.size() == 0) return {};

    	// Local variable
        std::unordered_map<int, int> numMap;

        // Traverse through input vector and prepare map accordingly
        for (int i = 0; i < nums.size(); ++i) {
            if (numMap.empty()) {
                numMap.insert(make_pair(nums[i], i));
            } else {
                auto find_iter = numMap.find(target - nums[i]);
                if (find_iter == numMap.end()) {
                    numMap.insert(make_pair(nums[i], i));
                } else {
                    return {find_iter->second, i};
                }
            }
        }

        return {};
    }
};

/*
 * Driver Code
 */
int main() {
	
	// TODO

	return 0;
}