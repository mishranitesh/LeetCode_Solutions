/*
	34. Find First and Last Position of Element in Sorted Array (MEDIUM)
	Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
	Your algorithm's runtime complexity must be in the order of O(log n).
	If the target is not found in the array, return [-1, -1].

	Input: nums = [5,7,7,8,8,10], target = 8		Input: nums = [5,7,7,8,8,10], target = 6
	Output: [3,4]									Output: [-1,-1]
*/


// Includes all standard library (ONLY for GCC, not standard C++ library)
#include <bits/stdc++.h>

using namespace std;

/*
 * Class to perform 'First and Last Position of Element' implementation
 */
class FirstLastPositionSolution {
public:

	// Method to implement 'First and Last Position of Element'
    vector<int> searchRange(vector<int>& nums, int target) {
        // Corner case
        if (nums.size() == 0 || target < nums[0]) return {-1, -1};
        if (nums.size() == 1 && target == nums[0]) return {0, 0};
        
        // Local variable
        int left = 0, right = nums.size(), mid = -1, lIndx, rIndx;
        
        // Using Binary Search Algorithm [O(logn)]
        while (left < right) {
            mid = (left + right) / 2;

            if (target == nums[mid]) {
                // Traverse to left side to find Left Index
                for (int i = mid; i >= 0; --i) {
                    if (nums[i] == target)
                        lIndx = i;
                    else
                        break;
                }
                
                // Traverse to right side to find Right Index
                for (int i = mid; i < nums.size(); ++i) {
                    if (nums[i] == target)
                        rIndx = i;
                    else
                        break;
                }
                
                return {lIndx, rIndx};
            } else if (target < nums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return {-1, -1};
    }
};


/*
 * Driver Code
 */
int main() {
	
	// TODO

	return 0;
}