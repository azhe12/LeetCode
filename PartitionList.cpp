/*  azhe
 *  2014/6/3
 *  https://oj.leetcode.com/problems/partition-list/
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
    ListNode *partition(ListNode *head, int x) {
        if (!head)
            return NULL;
        ListNode * l1 = NULL;
        ListNode * l1_head = NULL;
        ListNode * l2 = NULL;
        ListNode * l2_head = NULL;
        ListNode * p;
        p = head;
        while (p) {
            if (p->val < x) {       /*小于*/
                if (!l1_head) {     /*l1头节点*/
                    l1_head = p;
                    l1 = l1_head;
                } else {
                    l1->next = p;
                    l1 = p;
                }
            } else {                /*大于等于*/
                if (!l2_head) {     /*l2头节点*/
                    l2_head = p;
                    l2 = l2_head;
                } else {
                    l2->next = p;
                    l2 = p;
                }
            }
            p = p->next;
        }
        if (!l1) {
            l2->next = NULL;
            return l2_head;
        }
        if (!l2) {
            l1->next = NULL;
            return l1_head;
        }
        l1->next = l2_head;
        l2->next = NULL;
        return l1_head;
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
    class Solution so;
    //ListNode h(1);
    ListNode h(4);
    ListNode * newL;
    add_value_to_list(&h, 4);
    add_value_to_list(&h, 3);
    //add_value_to_list(&h, 2);
    add_value_to_list(&h, 5);
    //add_value_to_list(&h, 2);

    newL = so.partition(&h, 3);

    print_list(newL);
    return 0;
}
