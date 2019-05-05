/*
	283. Move Zeroes (EASY)
	Given an array nums, write a function to move all 0's to the end of it
	while maintaining the relative order of the non-zero elements.
	You must do this in-place without making a copy of the array.

	Input: 	[0,1,0,3,12]
	Output: [1,3,12,0,0]
*/


// Includes all standard library (ONLY for GCC, not standard C++ library)
#include <bits/stdc++.h>

using namespace std;

/*
 * Class to perform 'Move Zeroes' implementation
 */
class MoveZeroesSolution {
public:

	// Method to implement 'Move Zeroes'
    void moveZeroes(vector<int>& nums) {
        // Corner case
        if (nums.size() <= 1) return;
        
        // Local variable
        int zeroIndx = -1;

        // Traverse through input array
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0 && zeroIndx == -1)
                zeroIndx = i;

            // Swap non-zero number with zero indexed number
            if (nums[i] != 0 && zeroIndx != -1) {
                swap(nums[i], nums[zeroIndx]);
                ++zeroIndx;
            }
        }
    }
};

/*
 * Driver Code
 */
int main() {
	
	// TODO

	return 0;
}