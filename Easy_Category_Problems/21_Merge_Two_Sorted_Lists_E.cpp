/*
	21. Merge Two Sorted Lists (EASY)
	Merge two sorted linked lists and return it as a new list.
	The new list should be made by splicing together the nodes of the first two lists.

	Input: 1->2->4, 1->3->4
	Output: 1->1->2->3->4->4
*/

// Includes all standard library (ONLY for GCC, not standard C++ library)
#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

/*
 * Class to perform 'Merge Two Sorted Lists' implementation
 */
class MergeTwoSortedListsSolution {
public:

	// Method to implement 'Merge Two Sorted Lists'
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	// Corner case
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        // Local variable
        ListNode *mergedHead = new ListNode(0), *tempNode = mergedHead;

        // Traverse through both lists and merge to prepare new list
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                tempNode->next = l1;
                l1 = l1->next;
            } else {
                tempNode->next = l2;
                l2 = l2->next;
            }
            tempNode = tempNode->next;
        }

        // Logic when any one of the lists contains additional nodes
        if (l1 == nullptr)
            tempNode->next = l2;
        else if (l2 == nullptr)
            tempNode->next = l1;

        return mergedHead->next;
    }
};

/*
 * Driver Code
 */
int main() {

	// TODO

	return 0;
}