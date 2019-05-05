/*
	74. Search a 2D Matrix (MEDIUM)
	Write an efficient algorithm that searches for a value in an m x n matrix.
	This matrix has the following properties:
		Integers in each row are sorted from left to right.
		The first integer of each row is greater than the last integer of the previous row.

	Input:								Input:
		matrix = [							matrix = [
		  [1,   3,  5,  7],							   [1,   3,  5,  7],
		  [10, 11, 16, 20],							   [10, 11, 16, 20],
		  [23, 30, 34, 50]							   [23, 30, 34, 50]
		]											 ]
		target = 3							target = 13
	Output:								Output:
		true								false
*/


// Includes all standard library (ONLY for GCC, not standard C++ library)
#include <bits/stdc++.h>

using namespace std;

/*
 * Class to perform 'Search a 2D Matrix' implementation
 */
class Search2DMatrixSolution {
public:

	// Method to implement 'Search a 2D Matrix'
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Corner Case
        if (matrix.size() == 0) return false;
        
        // Local Variable
        int row = matrix.size(), col;

        // Traverse through matrix and find correct Sorted Row for binary search
        for (int i = 0; i < row; ++i) {
            col = matrix[i].size();
            if (col > 0)
                if (target == matrix[i][0] || target == matrix[i][col - 1])
                    return true;
                else if (target > matrix[i][0] && target < matrix[i][col - 1])
                    return binarySearch(matrix[i], target);
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