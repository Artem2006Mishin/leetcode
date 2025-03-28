/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val; 
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* reverseList(ListNode* head)
	{
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
		ListNode* first = head, * second = head->next, *next;
		first->next = nullptr;
		while (second) {
			next = second->next;
			second->next = first;
			first = second;
			second = next;
		}

		return first;
	}
};
