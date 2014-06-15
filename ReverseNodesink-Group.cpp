/*  azhe
 *  2014/6/15
 *  https://oj.leetcode.com/problems/reverse-nodes-in-k-group/
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
    ListNode * reverse(ListNode * head, ListNode * last)
    {
        ListNode * newHead = head;
        ListNode * p = head->next;
        ListNode * pre = head;
        while (p != last) {
            ListNode *next = p->next;
            pre->next = p->next;
            p->next = newHead;
            newHead = p;
            p = next;
        }
        return newHead;
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k <= 1)
            return head;
        int i = 1;
        ListNode * p = head;
        ListNode * start = head;
        ListNode * newHead = head;
        ListNode * preGroupLast = NULL;

        while (p != NULL) {
            if (i >= k) {
                //每个reverse group的head
                ListNode * tmpHead = reverse(start, p->next);
                if (newHead == head)   //最终结果的head是第一次reverse group的head
                    newHead = tmpHead;

                if (preGroupLast) //上个reverse group的last元素
                    preGroupLast->next = tmpHead;

                preGroupLast = start;

                p = start->next;
                if (p == NULL)  //到结尾
                    break;
                cout<<"new start: "<<p->val<<endl;
                start = p;
                i = 1;
            }
            p = p->next;
            i++;
        }
        return newHead;
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
    ListNode h2(2);

#if 0
    head.next = &h2;
#else
    ListNode h3(3);
    ListNode h4(4);
    ListNode h5(5);
    ListNode h6(6);
    head.next = &h2;
    h2.next = &h3;
    h3.next = &h4;
    h4.next = &h5;
    h5.next = &h6;

#endif

    ListNode *res;
    //res = so.reverse(&head, NULL);
    res = so.reverseKGroup(&head, 2);
    print_list(res);
}
