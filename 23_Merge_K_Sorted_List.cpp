/*
	23. Merge k Sorted Lists (HARD)
	Merge k sorted linked lists and return it as one sorted list.
	Input:
	[
	  1->4->5,
	  1->3->4,
	  2->6
	]
	Output: 1->1->2->3->4->4->5->6
*/


// Includes all standard library (ONLY for GCC, not standard C++ library)
#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list
struct ListNode {
	int val;
 	ListNode *next;
 	ListNode(int x) : val(x), next(NULL) {}
 };

/*
 * Class to perform 'Merge K Lists' implementation
 */
class MergeKListsSolution {
private:
    // Functor to sort as per pair's first value
    class Comparator {
    public:
        bool operator()(const pair<int, ListNode*>& p1, const pair<int, ListNode*>& p2) {
            return (p1.first > p2.first); // MIN-HEAP
        }
    };

public:

    /* 
     * Method to implement 'Merge K Lists'
     * Using Priority Queue -- Time Complexity O(Nlogk)
     * k = number of linked lists
     * N = total number of elements
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Corner case
        if (lists.size() == 0) return nullptr;
        if (lists.size() == 1) return lists[0];

        // Local variable
        ListNode *mergedList = nullptr, *tempNode = nullptr;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, Comparator> pairQueue;

        // Fill priority queue with individual list and corresponsing head value
        for (auto list : lists) {
            if (list != nullptr)
                pairQueue.push(make_pair(list->val, list));
        }

        // Traverse through priority queue
        while (!pairQueue.empty()) {
            auto tempPair = pairQueue.top();
            pairQueue.pop();

            // Prepare final merged linked list
            if (mergedList == nullptr) {
                mergedList = new ListNode(tempPair.first);
                tempNode = mergedList;
            } else {
                tempNode->next = new ListNode(tempPair.first);
                tempNode = tempNode->next;
            }

            // Modify priority queue if list still contains elements
            ListNode *tmp = tempPair.second->next;
            if (tmp)
                pairQueue.push(make_pair(tmp->val, tmp));
        }

        return mergedList;
    }
};

/*
 * Driver Code
 */
int main() {
	
	// TODO

	return 0;
}