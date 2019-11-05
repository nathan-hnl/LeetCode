/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        /*
         * Runtime: 12 ms, faster than 72.83% of C++ online submissions for Remove Duplicates from Sorted List.
         * Memory Usage: 9.2 MB, less than 98.11% of C++ online submissions for Remove Duplicates from Sorted List.
        */
        ListNode *curItr = head;
        while (curItr != nullptr && curItr->next != nullptr)
        {
            if (curItr->val == curItr->next->val)
            {
                ListNode *tmp = curItr->next;
                curItr->next = tmp->next;
                delete tmp;
                tmp = nullptr;
            }
            else
                curItr = curItr->next;
        }

        return head;
    }
};

