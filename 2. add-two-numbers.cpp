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

#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *resHead = new ListNode();
        ListNode *p = l1, *q = l2, *cur = resHead;
        int carry = 0;
        while (p != nullptr || q != nullptr)
        {
            int x = (p != nullptr) ? p->val : 0;
            int y = (q != nullptr) ? q->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (p != nullptr) p = p->next;
            if (q != nullptr) q = q->next;
        }
        if (carry > 0)
        {
            cur->next = new ListNode(carry);
        }
        
        return resHead->next;
    }
};