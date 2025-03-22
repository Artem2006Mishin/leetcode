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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty()) return nullptr;

		while (lists.size() > 1) {
			vector<ListNode*> temp;
			for (size_t i = 0; i < lists.size(); i += 2) {
				ListNode* l1 = lists[i];
				ListNode* l2 = (i + 1 < lists.size()) ? lists[i + 1] : nullptr;
				temp.push_back(mergeTwoLists(l1, l2));
			}
			lists = temp;
		}
		return lists[0];
	}
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode dummy;
		ListNode* tail = &dummy;

		while (l1 && l2) {
			if (l1->val < l2->val) {
				tail->next = l1;
				l1 = l1->next;
			}
			else {
				tail->next = l2;
				l2 = l2->next;
			}
			tail = tail->next;
		}

		if (l1) tail->next = l1;
		else if (l2) tail->next = l2;

		return dummy.next;
	}
};
