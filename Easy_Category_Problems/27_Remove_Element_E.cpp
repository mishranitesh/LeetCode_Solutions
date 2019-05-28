/*
	27. Remove Element (EASY)
	Given an array nums and a value val, remove all instances of that value in-place and return the new length.
	Do not allocate extra space for another array, modifying the input array in-place with O(1) extra memory.

	nums = [3,2,2,3], val = 3
	length = 2 		[2,2]

	nums = [0,1,2,2,3,0,4,2], val = 2
	length = 5		[0,1,3,0,4]
*/

// Includes all standard library (ONLY for GCC, not standard C++ library)
#include <bits/stdc++.h>

using namespace std;

/*
 * Class to perform 'Remove Element' implementation
 */
class RemoveElementSolution {
public:

	// Method to implement 'Remove Element'
    int removeElement(vector<int>& nums, int val) {
        removeElementHelper(nums, val, nums.size(), 0);
        return nums.size();
    }

private:
	// Method to modify input vector by erasing elements
	void removeElementHelper(vector<int>& nums, int val, int size, int index) {
		// Base Case
        if (index == size) return;

        // Erase element if equal to val
        if (nums[index] == val)
            nums.erase(nums.begin() + index);
        else
            ++index;

        // Recursion Case
        removeElementHelper(nums, val, nums.size(), index);
    }
};

/*
 * Driver Code
 */
int main() {

	// TODO

	return 0;
}