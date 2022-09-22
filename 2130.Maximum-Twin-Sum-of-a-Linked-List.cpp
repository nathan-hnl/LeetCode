/*
 *
 In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.
 For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
 The twin sum is defined as the sum of a node and its twin.
 Given the head of a linked list with even length, return the maximum twin sum of the linked list.
*/
#include <algorithm>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int pairSum(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* last = slow->next;
    while (last->next)
    {
        ListNode* cur = last->next;
        last->next = cur->next;
        cur->next = slow->next;
        slow->next = cur;
    }

    int res = 0;
    ListNode* x = head;
    ListNode* y = slow->next;
    while (y)
    {
        res = max(res, x->val + y->val);
        x = x->next;
        y = y->next;
    }

    return res;
}