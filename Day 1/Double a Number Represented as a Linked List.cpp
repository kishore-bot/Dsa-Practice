// LINKED LIST
// MEDIUM
// https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/

// Question
/*
double the given linked list value;
value of each node  from 0-9;
*/

// Idea 1
/*
 reverse Linked list
 Multiply by 2
 reverse linked list

*/

// Idea 2
/*
we need to multiply by two ->the idea is the max value is 18 (9*2) and max carry we get is 1
so we use prev pointer and curr pointer
 * curr pointer multiply the value by two
 * if answer greater than 10
 * add 1 to prev vale and update curr value by answer%10
 * move pointer
 * only edge case for head
*/
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        if (head == NULL)
            return head;
        ListNode *curr = head, *prev = NULL;
        while (curr != NULL) {
            int newVal = curr->val * 2;
            if (newVal < 10) {
                curr->val = newVal;
            } else {
                curr->val = newVal % 10;
                if (prev == nullptr) {
                    ListNode* newNode = new ListNode(1);
                    head = newNode;
                    head->next = curr;
                } else {
                    prev->val = prev->val + newVal / 10;
                }
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};

// https://www.youtube.com/watch?v=KpjU5dy-ZcA