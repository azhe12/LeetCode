/*  azhe
 *  2014/5/30
 *  https://oj.leetcode.com/problems/rotate-list/
 *  Note: 注意分别考虑以下情况
 *  1.  k > n
 *  2.  k % n == 0, 不移动
 *  所以先要求出链表长度
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
    ListNode *rotateRight(ListNode *head, int k) {
        int n;
        ListNode *p;
        ListNode *q;
        ListNode * pre;

        if (head == NULL)
            return NULL;

        p = head;
        n = 0;
        while (p != NULL) {     /*第一次遍历链表，求长度*/
            p = p->next;
            n++;
        }

        k = k % n;              /*考虑k>=n情况*/

        if (k == 0)             /*不移动*/
            return head;
        p = head;
        q = head;
        int i = 0;
        while (p != NULL) {     /*前后指针p,q*/
            if (i > k) {
                q = q->next;
            }
            pre = p;
            p = p->next;
            i++;
        }
        ListNode * new_head;
        new_head = q->next;
        q->next = NULL;
        pre->next = head;

        return new_head;
    }
};

int isEmpty(ListNode* head)
{
    //return (head->next == NULL)?1:0;
    return (head == NULL)?1:0;
}

void insert_node_head(ListNode* head, ListNode *node)
{
    ListNode *t;
    if (isEmpty(head)) {
        head = node;

        cout<<"insert "<<node->val<<" to empty list"<<endl;
    } else {
#if 0
        t = head->next;
        head->next = node;
        node->next = t;
        cout<<head->next->val<<"->"<<t->val<<endl;
#endif
        t = head;
        head = node;
        head->next = t;
        //cout<<node->val<<endl;
    }
}

void insert_node_back(ListNode* head, ListNode* node)
{
    ListNode *i = head;
    while (i->next != NULL)
        i = i->next;
    i->next = node;
    node->next = NULL;
}

void add_value_to_list(ListNode* head, int val)
{
    ListNode *node = new ListNode(val);
    //node->val = val;
    //insert_node_head(head, node);
    insert_node_back(head, node);
    //cout<<node->val<<endl;
}

void print_list(ListNode* head)
{
    ListNode* node = head;

    while (node != NULL) {
        cout<<node->val<<endl;
        node = node->next;
    }
}

int main()
{
    Solution so;
    ListNode head(1);
    //add_value_to_list(&head, 2);
    //add_value_to_list(&head, 3);
    //add_value_to_list(&head, 4);
    //add_value_to_list(&head, 5);
    ListNode *res;
    res = so.rotateRight(&head, 1);
    print_list(res);
}

