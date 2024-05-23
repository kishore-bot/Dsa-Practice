// Medium
// LL
// https://leetcode.com/problems/swap-nodes-in-pairs/description/

// Itaration

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL or head->next == NULL)
            return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        head = head->next;
        while (curr != NULL && curr->next != NULL) {
            ListNode* temp = curr;
            ListNode* nextNode = curr->next;
            curr = nextNode->next;
            temp->next = curr;
            nextNode->next = temp;
            if (prev != NULL)
                prev->next = nextNode;
            prev = temp;
        }
        return head;
    }
};

// Recursive

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL or head->next == NULL)
            return head;
        ListNode* prev = head->next;
        head->next = swapPairs(head->next->next); //or head->next = swapPairs(prev->next);
        prev->next = head;
        return prev;
    }
};
// https://youtu.be/OY09-51I-K0?si=okWc5IdHN0YPsNNL
