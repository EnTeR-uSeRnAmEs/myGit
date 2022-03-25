/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

//private include
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
// /**
//  * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//  */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *re, *p;
        re = new ListNode;
        re -> next = NULL;
        p = re;
        int tmp = 0;
        while (l1 != NULL || l2 != NULL || tmp) {
            int num1, num2;
            if (l1 != NULL) num1 = l1 -> val;
            else num1 = 0;
            if (l2 != NULL) num2 = l2 -> val;
            else num2 = 0;
            tmp = num1 + num2 + tmp;
            p -> val = tmp % 10;
            tmp /= 10;
            if (l1 != NULL) l1 = l1 -> next;
            if (l2 != NULL) l2 = l2 -> next;
            if (l1 != NULL || l2 != NULL || tmp) {
                ListNode *pNext = new ListNode;
                pNext -> next = NULL;
                p -> next = pNext;
                p = pNext;
            }
        }
        return re;
    }
};
// @lc code=end

