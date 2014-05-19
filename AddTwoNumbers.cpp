/*  azhe
 *  2014/5/15
 *  http://oj.leetcode.com/problems/add-two-numbers/
 * */
#include <iostream>

using namespace std;

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
    /* Wrong Answer:
Input:  {9}, {1,9,9,9,9,9,9,9,9,9}
Output: {8,0,4,5,6,0,0,1,4,1}
Expected:   {0,0,0,0,0,0,0,0,0,0,1}
     * */
#if 0
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        int sum1 = 0;
        int i = 1;
        while (l1 != NULL) {
            sum1 += l1->val * i;
            i *= 10;
            l1 = l1->next;
        }

        int sum2 = 0;
        i = 1;
        while (l2 != NULL) {
            sum2 += l2->val * i;
            i *= 10;
            l2 = l2->next;
        }
        
        int sum = sum1 + sum2;

        ListNode *head = new ListNode(sum % 10);
        sum /= 10;
        ListNode * p = head;
        while (sum != 0) {
            p->next = new ListNode(sum % 10);
            sum /= 10;
            p = p->next;
        }
        p = NULL;

        return head;
    }
#endif
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        
        int k = 0;      /*加法进位*/
        ListNode * head = new ListNode((l1->val + l2->val) % 10);
        ListNode * p = head;
        k = (l1->val + l2->val) / 10;
        l1 = l1->next;
        l2 = l2->next;

        while (l1 != NULL && l2 != NULL) {
            p->next = new ListNode((l1->val + l2->val + k) % 10);
            k = (l1->val + l2->val + k) / 10;
            l1 = l1->next;
            l2 = l2->next;
            p = p->next;
        }


        if (l1 == NULL && l2 != NULL) {
            while (l2 != NULL) {
                p->next = new ListNode((l2->val + k) % 10);
                p = p->next;
                k = (l2->val + k) / 10;
                l2 = l2->next;
            }
        } else if (l2 == NULL && l1 != NULL) {
            while (l1 != NULL) {
                p->next = new ListNode((l1->val + k) % 10);
                p = p->next;
                k = (l1->val + k) / 10;
                l1 = l1->next;
            }
        }

        if (l1 == NULL && l2 == NULL) {
            if (k == 1) {
                p->next = new ListNode(1);
            }
        }
        return head;
    }
};

int main()
{
    ListNode l1(3);
    ListNode l2(8);
    ListNode l3(9);
    l2.next = &l3;
    Solution so;
    ListNode * head;
    head = so.addTwoNumbers(&l1, &l2);
    while (head != NULL) {
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<endl;
}
