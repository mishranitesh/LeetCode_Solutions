/*
	238. Product of Array Except Self (MEDIUM)
	Given an array nums of n integers where n > 1, return an array output 
	such that output[i] is equal to the product of all the elements of nums except nums[i].
	Please solve it without division and in O(n).

	Input:  [1,2,3,4]
	Output: [24,12,8,6]
*/


// Includes all standard library (ONLY for GCC, not standard C++ library)
#include <bits/stdc++.h>

using namespace std;

/*
 * Class to perform 'Product of Array Except Self' implementation
 */
class ArrayProductExceptSelfSolution {
public:

	// Method to implement 'Product of Array Except Self'
    vector<int> productExceptSelf(vector<int>& nums) {
        // Corner case
        if (nums.size() == 0) return {};
        if (nums.size() == 1) return {1};
        
        // Local variable
        int size = nums.size();
        vector<int> frontProduct(size), backProduct(size), finalProduct(size);
        
        // Fill front product vector
        frontProduct[0] = 1;
        for (int i = 1; i < size; ++i)
            frontProduct[i] = frontProduct[i - 1] * nums[i - 1];
        
        // Fill back product vector
        backProduct[size - 1] = 1;
        for (int i = (size - 2); i >=0; --i)
            backProduct[i] = backProduct[i + 1] * nums[i + 1];
        
        // Prepare final product vector
        for (int i = 0; i < size; ++i)
            finalProduct[i] = frontProduct[i] * backProduct[i];
        
        return finalProduct;
    }
};

/*
 * Driver Code
 */
int main() {
	
	// TODO

	return 0;
}