/*
	26. Remove Duplicates from Sorted Array (EASY)
	Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

	nums = [1,1,2]
	length = 2 		[1,2]

	nums = [0,0,1,1,1,2,2,3,3,4]
	length = 5		[0,1,2,3,4]
*/

// Includes all standard library (ONLY for GCC, not standard C++ library)
#include <bits/stdc++.h>

using namespace std;

/*
 * Class to perform 'Remove Duplicates from Sorted Array' implementation
 */
class RemoveDuplicatesSolution {
public:

	// Method to implement 'Remove Duplicates from Sorted Array'
	int removeDuplicates(vector<int>& nums) {
        // Corner Case
        if (nums.size() <= 1) return nums.size();

        /*
         * Efficient Approach -- Using iterator and replace logic
         */
        auto replaceIter = nums.begin();

        for (auto curIter = nums.begin() + 1; curIter != nums.end(); ++curIter) {
        	// Increase replace iterator and then replace value
            if (*curIter != *replaceIter) {
            	++replaceIter;
                *replaceIter = *curIter;
            }
        }

        return (replaceIter - nums.begin() + 1);

        /*
         * Brute Force Approach --- Using vector::erase function
         */
        /*for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                nums.erase(nums.begin() + i);
                --i;
            }
        }
        return nums.size();*/
    }
};

/*
 * Driver Code
 */
int main() {

	// TODO

	return 0;
}