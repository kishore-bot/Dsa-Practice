// EASY
// https://leetcode.com/problems/merge-two-sorted-lists/description/

// ITAATE WAY 


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        ListNode* newHead = new ListNode(-1);
        ListNode *h1 = list1, *h2 = list2, *t = newHead;
        while (h1 != NULL and h2 != NULL) {
            if (h1->val <= h2->val) {
                t->next = h1;
                h1 = h1->next;
            } else {
                t->next = h2;
                h2 = h2->next;
            }
            t = t->next;
        }
        if (h1 != NULL)
            t->next = h1;
        if (h2 != NULL)
            t->next = h2;
        return newHead->next;
    }
};


// RECURSION CHAT GPT
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};