/*  azhe
 *  2014/4/24
 *
 * */
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /*  思路: 使用两个指针，front提前back指针n个Node;
     *  关键点: 1. 注意n = list length的情况
     *
     * */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode * newHead = head;
        ListNode * front = head;
        ListNode * back = head;
        ListNode * tmp;
        int i = 0;
        while (front != NULL && i < n) {
            front = front->next;
            i++;
        }
        if (i == n && front == NULL) {
            newHead = head->next;
            return newHead;
        }
        if (front == NULL)
            return NULL;
        while (front->next != NULL) {
            front = front->next;
            back = back->next;
        }
        tmp = back->next;
        back->next = back->next->next;
        delete tmp;
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
    class Solution so;
    ListNode *newHead;
    ListNode head(1);
    add_value_to_list(&head, 2);
    add_value_to_list(&head, 3);
    add_value_to_list(&head, 4);
    add_value_to_list(&head, 5);
    //print_list(&head);

    newHead = so.removeNthFromEnd(&head, 5);
    if (!newHead) {
        cout<<"remove failed"<<endl;
    }
    print_list(newHead);
}

