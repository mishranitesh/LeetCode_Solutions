/*
	445. Add Two Numbers II (MEDIUM)
	You are given two non-empty linked lists representing two non-negative integers.
	The most significant digit comes first and each of their nodes contain a single digit.
	Add the two numbers and return it as a linked list.
	Note:
		Reversing the lists is not allowed.

	Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
	Output: 7 -> 8 -> 0 -> 7
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
 * Class to perform 'Add Two Numbers II' implementation
 */
class AddTwoNumbersIISolution {
public:

	// Method to implement 'Add Two Numbers II'
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Corner case
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        
        // Local variables
        stack<int> l1Stk, l2Stk;
        int sum = 0, carry = 0;
        ListNode *head = nullptr;

        // Prepare first Stack from first input linked-list
        while (l1) {
            l1Stk.push(l1->val);
            l1 = l1->next;
        }

        // Prepare second Stack from second input linked-list
        while (l2) {
            l2Stk.push(l2->val);
            l2 = l2->next;
        }

        // Traverse through both Stacks
        while (!l1Stk.empty() && !l2Stk.empty()) {
            auto l1N = l1Stk.top(), l2N = l2Stk.top();
            l1Stk.pop();
            l2Stk.pop();
            sum = (l1N + l2N + carry);
            carry = sum / 10;
            sum = sum % 10;

            auto tempNode = new ListNode(sum);
            tempNode->next = head;
            head = tempNode;
        }

        // When first Stack still contains numbers
        while (!l1Stk.empty()) {
            auto l1N = l1Stk.top();
            l1Stk.pop();
            sum = (l1N + carry);
            carry = sum / 10;
            sum = sum % 10;
            
            auto tempNode = new ListNode(sum);
            tempNode->next = head;
            head = tempNode;
        }

        // When second Stack still contains numbers
        while (!l2Stk.empty()) {
            auto l2N = l2Stk.top();
            l2Stk.pop();
            sum = (l2N + carry);
            carry = sum / 10;
            sum = sum % 10;
            
            auto tempNode = new ListNode(sum);
            tempNode->next = head;
            head = tempNode;
        }

        // When carry is non-zero
        if (carry) {
            auto tempNode = new ListNode(carry);
            tempNode->next = head;
            head = tempNode;
        }

        return head;
    }
};

/*
 * Driver Code
 */
int main() {
	
	// TODO

	return 0;
}