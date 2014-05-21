/*  azhe
 *  2014/5/21
 *  https://oj.leetcode.com/problems/merge-k-sorted-lists/
 * */
#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
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



class Solution {
public:
    ListNode *mergeTwoSortedList(ListNode * l1, ListNode* l2)
    {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode * head;
        ListNode * tmp;
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        if (p1->val <= p2->val) {
            head = new ListNode(p1->val);
            p1 = p1->next;
        } else {
            head = new ListNode(p2->val);
            p2 = p2->next;
        }

        tmp = head;
        while (p1 != NULL && p2 != NULL) {
            while ((p1 != NULL) && (p1->val <= p2->val)) {
                tmp->next = new ListNode(p1->val);
                tmp = tmp->next;
                p1 = p1->next;
            }
            if (p1 == NULL)     /*l1结束*/
                break;
            while ((p2 != NULL) && (p2->val < p1->val)) {
                tmp->next = new ListNode(p2->val);
                tmp = tmp->next;
                p2 = p2->next;
            }
            if (p2 == NULL)     /*l2结束*/
                break;
        }

        if (p1 == NULL) {
            while (p2 != NULL) {
                tmp->next = new ListNode(p2->val);
                tmp= tmp->next;
                p2 = p2->next;
            }
        }
        if (p2 == NULL) {
            while (p1 != NULL) {
                tmp->next = new ListNode(p1->val);
                tmp = tmp->next;
                p1 = p1->next;
            }
        }
        
        return head;
    }
    ListNode *mergeRecur(vector<ListNode *> & lists, int begin, int end)
    {
        if (begin > end)
            return NULL;
        if (begin == end)
            return lists[begin];

        if (end - begin == 1) { /*只剩下2个list合并*/
            return mergeTwoSortedList(lists[begin], lists[end]);
        }

        /*二分法: 多于2个list*/
        int mid = (begin + end) / 2;
        ListNode * left = mergeRecur(lists, begin, mid);
        ListNode * right = mergeRecur(lists, mid + 1, end);
        //cout<<"left:"<<endl;
        //print_list(left);
        //cout<<"right:"<<endl;
        //print_list(right);
        //cout<<"end"<<endl;
        return mergeTwoSortedList(left, right);
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0)
            return NULL;
        return mergeRecur(lists, 0, lists.size() - 1);
    }
};

int main()
{
    class Solution so;
    ListNode l1(1);
    ListNode l2(3);
    ListNode l3(2);


    add_value_to_list(&l1, 7);
    add_value_to_list(&l1, 8);

    add_value_to_list(&l2, 4);
    add_value_to_list(&l2, 6);

    add_value_to_list(&l3, 10);
    add_value_to_list(&l3, 20);

    vector<ListNode*> lv;
#if 0
    lv.push_back(&l1);
    lv.push_back(&l2);
    lv.push_back(&l3);
#endif
    ListNode l4(1);
    ListNode l5(0);
    lv.push_back(&l4);
    lv.push_back(&l5);
    //ListNode * newL = so.mergeKLists(lv);
    //ListNode * newL = so.mergeTwoSortedList(&l1, &l2);
    ListNode * newL = so.mergeTwoSortedList(&l4, &l5);

    print_list(newL);
    return 0;
}

