/*
	200. Number of Islands (MEDIUM)
	Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
	An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
	You may assume all four edges of the grid are all surrounded by water.

	Input:						Input:
		11110						11000
		11010						11000
		11000						00100
		00000						00011
	Output:						Output:
		1							3
*/


// Includes all standard library (ONLY for GCC, not standard C++ library)
#include <bits/stdc++.h>

using namespace std;

/*
 * Class to perform 'Number of Islands' implementation
 */
class NumberOfIslandsSolution {
public:
    
    /*
     * Method to implement 'Number of Islands'
     * Using DFS (Depth First Search)
     */
    int numIslands(vector<vector<char>>& grid) {
        // Corner case
        if (grid.size() == 0) return 0;
        
        // Local variable
        int islandsCount = 0, row = grid.size(), col = grid[0].size();
        
        // Traverse through input grid and explore each island
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '1') {
                    ++islandsCount;
                    exploreGridCellsRecursion(grid, i, j);
                }
            }
        }
        
        return islandsCount;
    }

private:

	// Method to explore input grid for respective island
	void exploreGridCellsRecursion(vector<vector<char>>& grid, int i, int j) {
        // Local variable
        int r = grid.size(), c = grid[0].size();
        
        // Base Case
        if (i < 0 || j < 0 || i >= r || j >= c || grid[i][j] != '1') return;
        
        // Cell explored
        grid[i][j] = 'e';
        
        // Recursion Case (Direction of movement {Left, Up, Right, Down})
        std::vector<std::pair<int, int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        for (auto &dir : directions)
            exploreGridCellsRecursion(grid, (i + dir.first), (j + dir.second));
    }
};

/*
 * Driver Code
 */
int main() {
	
	// TODO

	return 0;
}