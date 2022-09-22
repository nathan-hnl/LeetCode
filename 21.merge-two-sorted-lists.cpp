/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */
 /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
  */

#include <iostream>
#include <algorithm>
//#include <utility>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        //1. recursive
        //Runtime: 8 ms, faster than 99.76% of C++ online submissions for Merge Two Sorted Lists.
        //Memory Usage : 9.2 MB, less than 99.03% of C++ online submissions for Merge Two Sorted Lists.
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }

        //2.
        if (!l1 || (l2 && l1->val > l2->val))
            swap(l1, l2);
        if (l1)
        {
            l1->next = mergeTwoLists(l1->next, l2);
        }
        return l1;

        //3.
        ListNode *tempList = new ListNode(-1), *cur = tempList;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }

            cur = cur->next;
        }

        cur->next = l1 ? l1 : l2;
        return tempList->next;
    }
};

