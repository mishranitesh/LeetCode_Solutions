/*
	54. Spiral Matrix (MEDIUM)
	Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

	Input:								Input:
		[									[
		 [ 1, 2, 3 ],						 [1, 2, 3, 4],
		 [ 4, 5, 6 ],						 [5, 6, 7, 8],
		 [ 7, 8, 9 ]						 [9,10,11,12]
		]									]
	Output:								Output:
		[1,2,3,6,9,8,7,4,5]					[1,2,3,4,8,12,11,10,9,5,6,7]
*/


// Includes all standard library (ONLY for GCC, not standard C++ library)
#include <bits/stdc++.h>

using namespace std;

/*
 * Class to perform 'Spiral Matrix' implementation
 */
class SpiralMatrixSolution {
private:
    std::size_t _eleCount;

public:

    // Method to implement 'Spiral Matrix'
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Corner Case
        if (matrix.size() == 0) return {};

        // Local variable
        std::vector<int> spiralVect;
        _eleCount = matrix.size() * matrix[0].size();
        
        // Recursive call for other cases
        spiralOrderRecursive(matrix, 0, 0, 0, spiralVect);
        
        return spiralVect;
    }

private:
	// Recursive method to prepare final vector containing element in Spiral Order
    void spiralOrderRecursive(std::vector<vector<int>> &matrix, int r, int c, int direction, std::vector<int> &spiralVect) {
        // Base case
        if (_eleCount == 0) return;

        // Change the direction of flow to maintain spiral structure
        if (r < 0 || r >= matrix.size() || c < 0 || c >= matrix[0].size()
        	|| matrix[r][c] == numeric_limits<int>::min()) {

        	// Possible directions {0, 1, 2, 3}
            direction = (direction + 1) % 4;
            switch (direction) {
                case 0:
                    ++r; ++c; break;
                case 1:
                    ++r; --c; break;
                case 2:
                    --r; --c; break;
                case 3:
                    --r; ++c; break;
            }
        }
        
        // Push element in the result vector to maintain Spiral Order
        spiralVect.push_back(matrix[r][c]);
        matrix[r][c] = numeric_limits<int>::min();
        --_eleCount;
        
        // Change row or column indices according to direction
        switch (direction) {
            case 0:
                ++c; break;
            case 1:
                ++r; break;
            case 2:
                --c; break;
            case 3:
                --r; break;
        }
        
        // Recursive function call with updated parameters
        spiralOrderRecursive(matrix, r, c, direction, spiralVect);
    }
};

/*
 * Driver Code
 */
int main() {
	
	// TODO

	return 0;
}