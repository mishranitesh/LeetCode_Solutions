/*
	240. Search a 2D Matrix II (MEDIUM)
	Write an efficient algorithm that searches for a value in an m x n matrix.
	This matrix has the following properties:
		Integers in each row are sorted in ascending from left to right.
		Integers in each column are sorted in ascending from top to bottom.

	[
	  [1,   4,  7, 11, 15],
	  [2,   5,  8, 12, 19],
	  [3,   6,  9, 16, 22],
	  [10, 13, 14, 17, 24],
	  [18, 21, 23, 26, 30]
	]
	Given target = 5, return true.
	Given target = 20, return false.
*/


// Includes all standard library (ONLY for GCC, not standard C++ library)
#include <bits/stdc++.h>

using namespace std;

/*
 * Class to perform 'Search a 2D Matrix II' implementation
 */
class Search2DMatrixIISolution {
public:

    // Method to implement 'Search a 2D Matrix II'
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Corner case
        if (matrix.size() == 0) return false;

        // Traverse through each row of input matrix
        for (int i = 0; i < matrix.size(); ++i) {
            if (binarySearch(matrix[i], target))
                return true;
        }

        return false;
    }

private:

	// Method to perform binary search
	bool binarySearch(vector<int>& nums, int target) {
        // Corner case
        if (nums.size() == 0) return false;
        if (nums.size() == 1) return (nums[0] == target) ? true : false;
        
        // Local variables
        int first = 0, last = nums.size() - 1, mid = 0;

        // Binary search implementation
        while (first <= last) {
            mid = (first + last) / 2;

            // Break condition - when target element found
            if (nums[mid] == target) return true;

            // Modify first or last indices
            if (nums[mid] < target)
                first = mid + 1; 
            else
                last = mid - 1;
        }

        return false;
    }
};

/*
 * Driver Code
 */
int main() {
	
	// TODO

	return 0;
}