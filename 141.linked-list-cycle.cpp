/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<iostream>
#include<vector>
#include <algorithm>
#include<map>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
     };
     
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //1. using hash
        //Runtime: 804 ms, faster than 5.84% of C++ online submissions for Linked List Cycle.
        //Memory Usage: 8.4 MB, less than 13.58% of C++ online submissions for Linked List Cycle.
        vector<ListNode *> curHeads;
        while (head)
        {
            if(find(curHeads.begin(), curHeads.end(), head) != curHeads.end())
                return true;
            else
                curHeads.push_back(head);

            head = head->next;
        }
        return false;

        //Runtime: 36 ms, faster than 5.84% of C++ online submissions for Linked List Cycle.
        //Memory Usage: 10 MB, less than 6.98% of C++ online submissions for Linked List Cycle.
        map<ListNode *, bool> curMapHeads;
        while (head)
        {
            // if(curMapHeads.find(head) != curMapHeads.end())
            //     return true;
            // else
            //     curMapHeads.insert(make_pair(head, true));
            if (curMapHeads.count(head) != 0)
                return true;
            else
                curMapHeads.insert(make_pair(head, true));
  
            head = head->next;
        }
        return false;

        //2. double pointers
        //Runtime: 4 ms, faster than 99.79% of C++ online submissions for Linked List Cycle.
        //Memory Usage: 7.6 MB, less than 92.95% of C++ online submissions for Linked List Cycle.
        if (!head || !head->next)
            return false;

        ListNode *pSlow = head;
        ListNode *pFast = head->next;
        while (pSlow != pFast)
        {
            if (!pFast || !pFast->next)
                return false;

            pSlow = pSlow->next;
            pFast = pFast->next->next;
        }
        return true;
    }
};
// @lc code=end

