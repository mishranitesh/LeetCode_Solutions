/*
	141. Linked List Cycle (EASY)
	Given a linked list, determine if it has a cycle in it.
	To represent a cycle in the given linked list, we use an integer pos which represents 
	the position (0-indexed) in the linked list where tail connects to.
	If pos is -1, then there is no cycle in the linked list.

	Input: head = [3,2,0,-4], pos = 1		head = [1,2], pos = 0		head = [1], pos = -1
	Output: true							true						false
*/


// Includes all standard library (ONLY for GCC, not standard C++ library)
#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

/*
 * Class to perform 'Linked List Cycle' implementation
 */
class LinkedListCycleSolution {
public:

	/* 
	 * Method to implement 'Linked List Cycle'
	 * Tortoise-Rabbit (Two Pointer Approach)
	 */
    bool hasCycle(ListNode *head) {
        // Corner case
        if (!head || !(head->next) || !(head->next->next)) return false;

        // Local variable
        ListNode *slowIter = head, *fastIter = head->next->next;

        // Traverse until Fast Iterator reached tail of list
        while (fastIter != nullptr) {
        	// In case of cycle - Fast will meet Slow Iterator
            if (slowIter == fastIter) return true;

            // Modify slow and fast iterators
            slowIter = slowIter->next;
            if (fastIter->next && fastIter->next->next)
                fastIter = fastIter->next->next;
            else
                fastIter = nullptr;
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