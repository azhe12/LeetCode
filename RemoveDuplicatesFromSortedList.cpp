#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *node, *next;
        node = head;
        while (node != NULL && node->next != NULL) {
            next = node->next;
            if (next->val == node->val) {
                node->next = next->next;
            } else {
                node = node->next;
            }
        }
        return head;
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
    ListNode head(0);
#if 1
    add_value_to_list(&head, 1);
    add_value_to_list(&head, 2);
    add_value_to_list(&head, 2);
    add_value_to_list(&head, 3);
#endif

    so.deleteDuplicates(&head);
    print_list(&head);
}
