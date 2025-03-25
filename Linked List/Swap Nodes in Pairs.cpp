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
	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr) return head;
		if (head->next == nullptr) return head;

		ListNode dummy;
		ListNode* tail = &dummy;
		ListNode* r = head->next;
		ListNode* l = head;
		while (l && r) {
			// Сохраняем следующую пару
			ListNode* nextPair = r->next;
			
			// Переставляем текущую пару
			tail->next = r;
			r->next = l;
			tail = l;

			// Переходим к следующей паре
			l = nextPair;
			if (l) {
				r = l->next;
			}
			else {
				r = nullptr;
			}
		}

		// Если остался один узел без пары
		if (l) {
			tail->next = l;
			tail = l;
		}

		tail->next = nullptr;

		return dummy.next;
	}
};
