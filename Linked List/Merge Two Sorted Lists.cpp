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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Создаем фиктивный узел для упрощения кода
        ListNode dummy;
        ListNode* tail = &dummy;

        // Пока оба списка не пусты
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

        // Если один из списков не пуст, добавляем оставшиеся элементы
        if (l1) {
            tail->next = l1;
        }
        else if (l2) {
            tail->next = l2;
        }

        // Возвращаем объединенный список, начиная с первого узла после фиктивного
        return dummy.next;
    }
};
