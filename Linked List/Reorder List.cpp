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
    void reorderList(ListNode* head)
    {
		// найдем середину списка с помощью быстрого и медленного указателей
		ListNode* slow = head, *fast = head;
		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}

		// переворачиваем вторую половину списка
		ListNode* prev = nullptr, * next = nullptr, *curr = slow->next;
		slow->next = nullptr;
		while (curr) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}

		// объединяем две части списка
		ListNode* first = head, * second = prev;
		while (second) {
			ListNode* temp1 = first->next, * temp2 = second->next;
			first->next = second;
			second->next = temp1;
			first = temp1;
			second = temp2;
		}
    }
};
