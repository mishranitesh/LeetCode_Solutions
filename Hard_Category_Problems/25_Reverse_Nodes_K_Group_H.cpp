/*
	25. Reverse Nodes in k-Group (HARD)
	Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
	k is a positive integer and is less than or equal to the length of the linked list.
	If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

	Given this linked list: 1->2->3->4->5
	For k = 2, you should return: 2->1->4->3->5
	For k = 3, you should return: 3->2->1->4->5
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

// Macro to enable debug messages to check required node's value
#define DEBUG_MSG 														\
		if (_prevStart)													\
            cout << "\n_prevStart -->" << _prevStart->val << endl;		\
        else															\
            cout << "\n_prevStart -->" << "nullptr" << endl;			\
        if (_start)														\
            cout << "_start -->" << _start->val << endl;				\
        else															\
            cout << "_start -->" << "nullptr" << endl;					\
        if (_prev)														\
            cout << "_prev -->" << _prev->val << endl;					\
        else															\
            cout << "_prev -->" << "nullptr" << endl;					\
        if (_curr)														\
            cout << "_curr -->" << _curr->val << endl;					\
        else															\
            cout << "_curr -->" << "nullptr" << endl;					\
        if (_next)														\
            cout << "_next -->" << _next->val << endl;					\
        else															\
            cout << "_next -->" << "nullptr" << endl;

/*
 * Class to perform 'Reverse Nodes in k-Group' implementation
 */
class ReverseNodeskGroupSolution {    
public:

	// Method to implement 'Reverse Nodes in k-Group'
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Corner case
        if (!head || !head->next || k == 1) return head;
        
        // Initialize class data members
        _prev = nullptr;
        _curr = head;
        _start = head;
        _next = head->next;
        
        // Logic to reverse nodes in k-groups
        bool firstTime = true;
        while (isReversePossible(k)) {
            // Function to reverse k nodes from _start node
            reverseKNodes(k);
            
            // Change head for the first time
            if (firstTime) {
                head = _prev;
                firstTime = false;
            } else {
                _prevStart->next = _prev;
            }

            // Uncomment this macro in case to debug and check required nodes
            // DEBUG_MSG
            
            // Modify node pointers
            _prevStart = _start;
            if (_start)
                _start->next = _curr;
            _prev = _start;
            _start = _curr;
            if (_curr)
                _next = _curr->next;
        }
        
        return head;
    }

private:
	// Data Members
    ListNode *_prev;
    ListNode *_curr;
    ListNode *_start;
    ListNode *_next;
    ListNode *_prevStart;

    // Check for group of 'k' nodes reverse possibility
    bool isReversePossible(int k) {
        auto *tStart = _start;
        while (--k && tStart && tStart->next)
            tStart = tStart->next;
        
        return (k == 0) ? true : false;
    }

    // Method to reverse 'k' nodes in the list
    void reverseKNodes(int k) {
    	// Traverse till k is non-zero
        while (k) {
            _curr->next = _prev;
            _prev = _curr;
            _curr = _next;
            if (_next)
                _next = _next->next;
            --k;
        }
    }
};

/*
 * Driver Code
 */
int main() {

	// TODO

	return 0;
}