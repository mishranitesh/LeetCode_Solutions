/*
	15. 3Sum (MEDIUM)
	Given an array nums of n integers, are there elements a, b, c in nums such that "a + b + c = 0"
	Find all unique triplets in the array which gives the sum of zero.
	Input:
		nums = [-1, 0, 1, 2, -1, -4]
	Output:
		[
		  [-1, 0, 1],
		  [-1, -1, 2]
		]
*/


// Includes all standard library (ONLY for GCC, not standard C++ library)
#include <bits/stdc++.h>

using namespace std;

/*
 * Class to perform '3Sum' implementation
 */
class ThreeSumSolution {
public:

	// Method to implement '3Sum'
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Corner case
        if (nums.size() <= 2) return {};
        
        // Local variable
        int target = 0;
        unordered_map<int, int> valueMap; // Keeps (Value, Index)
        vector<vector<int>> finalTriplets;
        set<tuple<int, int, int>> tupleSet; // Identify duplicates

        // Fill map with 'Value and Index'
        for (int i = 0; i < nums.size(); ++i)
            valueMap.insert({nums[i], i});

        // Traverse through input vector and prepare final triplet vector
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                int rem = target - (nums[i] + nums[j]);

                // Check for remaining sum in Value Map
                auto iter = valueMap.find(rem);
                if (iter != valueMap.end() && iter->second != i && iter->second != j) {
                	// Prepare sorted vector of elements having sum = zero
                    vector<int> tempV = {rem, nums[i], nums[j]};
                    sort(tempV.begin(), tempV.end());

                    // Prepare tuple of triplets in sorted manner
                    auto tempTuple = make_tuple(tempV[0], tempV[1], tempV[2]);

                    // Push unique triplets into final vector
                    if (tupleSet.find(tempTuple) == tupleSet.end()) {
                        tupleSet.insert(move(tempTuple));
                        finalTriplets.push_back({get<0>(tempTuple), get<1>(tempTuple), get<2>(tempTuple)});
                    }
                }
            }
        }
        
        return finalTriplets;
    }
};

/*
 * Driver Code
 */
int main() {
	
	// TODO

	return 0;
}