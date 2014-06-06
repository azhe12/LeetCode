/*  azhe
 *  2014/6/3
 *  https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 * */
#include <iostream>

/**
 * Definition for singly-linked list.
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode * pre = NULL;
        ListNode * p = head;
        bool flag = false;
        while (p) {
            while (p->next && p->val == p->next->val) {
                p->next = p->next->next;
                flag = true;
            }
            if (flag) { /*有重复*/
                flag = false;
                if (!pre) {    /*开头就重复, pre==NULL*/
                    head = p->next;
                    p = head;
                } else {        /**/
                    pre->next = p->next;
                    p = pre->next;
                }
            } else {    /*没有重复*/
                pre = p;
                p = p->next;
            }
        }
        return head;
    }
};
