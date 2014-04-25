/* azhe
 *2014/4/25
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
    /*默认升序排列
     *
     * */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode* p1 = l1;
        ListNode* p1_pre;
        ListNode* p2 = l2;
        ListNode* p2_pre;
        ListNode* newL;
        ListNode* tmp;
        if (l1 == NULL && l2 == NULL)
            return NULL;
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        if (p1->val <= p2->val)
            newL = p1;
        else {
            newL = p2;
            tmp = p1;
            p1 = p2;
            p2 = tmp;
        }
        while (p1 != NULL && p2 != NULL) {
            while (p1 != NULL && p1->val <= p2->val) {
                p1_pre = p1;
                p1 = p1->next;
            }
            if (p1 == NULL) {
                p1_pre->next = p2;
                return newL;
            }
            p1_pre->next = p2;
            p2_pre = p2;
            p2 = p2->next;
            p2_pre->next = p1;
            p1_pre = p2_pre;
        }
        return newL;
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
    ListNode head2(1);
    ListNode head1(7);
    ListNode *newL;
#if 1
    add_value_to_list(&head2, 3);
    add_value_to_list(&head2, 4);
    add_value_to_list(&head2, 5);
    add_value_to_list(&head2, 10);
    add_value_to_list(&head1, 11);
#endif
    newL = so.mergeTwoLists(&head1, &head2);
    //newL = so.mergeTwoLists(&head1, NULL);
    print_list(newL);
}

