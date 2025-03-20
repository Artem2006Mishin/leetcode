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
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if (list1 == nullptr && list2 == nullptr) {
			return list1;
		}
		if (list1 == nullptr) {
			return list2;
		}
		if (list2 == nullptr) {
			return list1;
		}

		ListNode* answer = list1;
		bool condition = true;
		if (list1->val > list2->val) {
			condition = false;
			answer = list2;
		}

		while (list1 != nullptr || list2 != nullptr) {
			if (condition) {
				ListNode* next = list1->next;
				if (list1->next == nullptr) {
					list1->next = list2;
					break;
				}
				if (list1->next->val > list2->val) {
					list1->next = list2;
					list1 = next;
					condition = false;
				}
				else {
					list1 = next;
					condition = true;
				}
			}
			else {
				ListNode* next = list2->next;
				if (list2->next == nullptr) {
					list2->next = list1;
					break;
				}
				if (list2->next->val > list1->val) {
					list2->next = list1;
					list2 = next;
					condition = true;
				}
				else {
					list2 = next;
					condition = false;
				}
			}
		}
		return answer;
	}
};
