
/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast != NULL) {
        slow = slow->next;
    }

    struct ListNode *prev = NULL;
    struct ListNode *curr = slow;

    while (curr != NULL) {
        struct ListNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    struct ListNode *first = head;
    struct ListNode *second = prev;

    while (second != NULL) {
        if (first->val != second->val) {
            return false;
        }

        first = first->next;
        second = second->next;
    }

    return true;
}
