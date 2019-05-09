/*
	42. Trapping Rain Water (HARD)
	Given n non-negative integers representing an elevation map where the width of each bar is 1, 
	compute how much water it is able to trap after raining.

	Input: [0,1,0,2,1,0,1,3,2,1,2,1]
	Output: 6
	https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png
*/

// Includes all standard library (ONLY for GCC, not standard C++ library)
#include <bits/stdc++.h>

using namespace std;

/*
 * Class to perform 'Trapping Rain Water' implementation
 */
class TrappingRainWaterSolution {
public:

	// Method to implement 'Trapping Rain Water'
	int trap(vector<int>& height) {
        // Corner case
        if (height.size() == 0) return 0;
        
        // Local variable
        int trapUnit = 0, leftMax = 0, rightMax = 0;
        vector<int>::iterator startLeft = height.begin(), endRight = height.end() - 1;
        
        /*
         * Algorithm to compute trapUnit is as follows:
         * trapUnit += min(leftMax, rightMax) - height[index];
         */
        while (startLeft < endRight) {
            if (*startLeft <= *endRight) {
                if (*startLeft >= leftMax)
                    leftMax = *startLeft;
                else
                    trapUnit += (leftMax - *startLeft);
                ++startLeft;
            } else {
                if (*endRight >= rightMax)
                    rightMax = *endRight;
                else
                    trapUnit += (rightMax - *endRight);
                --endRight;
            }
        }

        return trapUnit;
    }
};

/*
 * Driver Code
 */
int main() {

	// TODO

	return 0;
}