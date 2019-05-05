/*
	199. Binary Tree Right Side View (MEDIUM)
	Given a binary tree, imagine yourself standing on the right side of it,
	return the values of the nodes you can see ordered from top to bottom.

	Input: [1,2,3,null,5,null,4]
	Output: [1, 3, 4]

	Explanation:

		   1            <---
		 /   \
		2     3         <---
		 \     \
		  5     4       <---
*/

// Includes all standard library (ONLY for GCC, not standard C++ library)
#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*
 * Class to perform 'Binary Tree Right Side View' implementation
 */
class BinaryTreeRightViewSolution {
public:

	/*
	 * Method to implement 'Binary Tree Right Side View'
	 * Using BFS (Breadth First Search)
	 */
    vector<int> rightSideView(TreeNode* root) {
        // Corner case
        if (!root) return {};
        if (!root->left && !root->right) return {root->val};

        // Local variable
        int prevLevel = -1;
        vector<int> rightViewVect;
        queue<pair<TreeNode*, int>> bfsQ;

        // Breadth First Search logic
        bfsQ.push({root, 0});
        while (!bfsQ.empty()) {
            auto tPair = bfsQ.front();
            bfsQ.pop();

            TreeNode *currNode = tPair.first;
            int currLevel = tPair.second;

            // Prepare right view vector for each new level of tree
            if (currLevel != prevLevel) {
                rightViewVect.emplace_back(currNode->val);
                ++prevLevel;
            }

            // First -> Right child and Second -> Left Child in Queue
            if (currNode->right)
                bfsQ.push({currNode->right, currLevel + 1});
            if (currNode->left)
                bfsQ.push({currNode->left, currLevel + 1});
        }
        
        return rightViewVect;
    }
};

/*
 * Driver Code
 */
int main() {
	
	// TODO

	return 0;
}