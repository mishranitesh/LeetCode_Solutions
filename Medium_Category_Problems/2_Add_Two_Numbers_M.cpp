/*
	2. Add Two Numbers (MEDIUM)
	You are given two non-empty linked lists representing two non-negative integers.
	The digits are stored in reverse order and each of their nodes contain a single digit.
	Add the two numbers and return it as a linked list.

	Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
	Output: 7 -> 0 -> 8
	Explanation: 342 + 465 = 807.
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
 * Class to perform 'Add Two Numbers' implementation
 */
class AddTwoNumbersSolution {
public:

	// Method to implement 'Add Two Numbers'
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Corner case
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        // Local variable
        int sum = 0, carry = 0;
        ListNode *itL1 = l1, *itL2 = l2, *headNode = nullptr, *itAns = nullptr;

        // Traverse through both the lists and prepare new list
        while (itL1 && itL2) {
            sum = itL1->val + itL2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            if (headNode == nullptr) {
                headNode = new ListNode(sum);
                itAns = headNode;
            } else {
                itAns->next = new ListNode(sum);
                itAns = itAns->next;
            }
            itL1 = itL1->next;
            itL2 = itL2->next;
        }

        // When first list still contains numbers
        while (itL1) {
            sum = itL1->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            itAns->next = new ListNode(sum);
            itAns = itAns->next;
            itL1 = itL1->next;
        }

        // When second list still contains numbers
        while (itL2) {
            sum = itL2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            itAns->next = new ListNode(sum);
            itAns = itAns->next;
            itL2 = itL2->next;
        }

        // When carry is not zero
        if (carry)
            itAns->next = new ListNode(1);

        return headNode;
    }
};

/*
 * Driver Code
 */
int main() {
	
	// TODO

	return 0;
}