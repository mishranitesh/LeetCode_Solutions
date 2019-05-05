/*
	138. Copy List with Random Pointer (MEDIUM)
	A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
	Return a deep copy of the list.

	Input:
		{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
	Output:
		{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

	Explanation:
		Node 1's value is 1, both of its next and random pointer points to Node 2.
		Node 2's value is 2, its next pointer points to null and its random pointer points to itself.
*/


// Includes all standard library (ONLY for GCC, not standard C++ library)
#include <bits/stdc++.h>

using namespace std;

// Definition for linked-list Node
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* random;

    ListNode() {}
    ListNode(int _val, ListNode* _next, ListNode* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

/*
 * Class to perform 'Copy List with Random Pointer' implementation
 */
class Solution {
public:

	// Method to implement 'Copy List with Random Pointer'
    ListNode* copyRandomList(ListNode *head) {
        // Corner Case
        if (!head) return head;

        // Local Variable
        unordered_map<ListNode*, ListNode*> elemMap, randMap;
        ListNode *newHead = nullptr, *currNode = nullptr, *tempNode = head;

        // Traverse through input list
        while (tempNode != nullptr) {

        	// Prepare singly-linked list with 'next' elements
            if (newHead == nullptr) {
                newHead = new ListNode(tempNode->val, nullptr, nullptr);
                currNode = newHead;
            } else {
                currNode->next = new ListNode(tempNode->val, nullptr, nullptr);
                currNode = currNode->next;
            }

            // Prepare element and random maps
            elemMap[tempNode] = currNode;
            if (tempNode->random != nullptr)
                randMap[tempNode] = tempNode->random;
            tempNode = tempNode->next;
        }

        // Traverse through Random Map and modify singly linked-list
        for (auto it : randMap) {
            auto it1 = elemMap.find(it.first);
            auto it2 = elemMap.find(it.second);
            it1->second->random = it2->second;
        }

        return newHead;
    }

private:
	// Method to display linked-list elements with random pointer
    void printList(ListNode *head) {
        cout << "Linked List Elements:" << endl;
        while (head != nullptr) {
            cout << "Label = " << head->val << " --> " << head->random;
            if (head->random != nullptr)
                cout << ", Random Label = " << head->random->val;
            cout << endl;
            head = head->next;
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