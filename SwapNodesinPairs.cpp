/* azhe
 *2014/4/26
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
    /*
     * 1. NULL      =>      NULL
     * 2. 1         =>      1
     * 3. 1->2      =>      2->1
     * 4. 1->2->3   =>      2->1->3
     * 5. 1->2->3->4    =>  2->1->4->3
     * */
    ListNode *swapPairs(ListNode *head) {
        ListNode * p;
        ListNode * pre = NULL;
        ListNode * next;
        ListNode * t;
        ListNode * new_head;

        if (head == NULL)   /*1*/
            return NULL;
        else if (head->next == NULL)    /*2*/
            return head;

        p = head;
        next = p->next;
        new_head = next;

        while (p != NULL && p->next != NULL) { /*3 ~ 5*/
            if (pre != NULL)
                pre->next = p->next;
            next = p->next;
            t = next->next;
            next->next = p;
            //p->next = t;
            pre = p;
            p = t;
        }
        if (p == NULL)
            pre->next = NULL;
        else if (p->next == NULL)
            pre->next = p;
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
    class Solution so;
    ListNode head1(1);

    ListNode head2(1);
    add_value_to_list(&head2, 2);

    ListNode head3(1);
    add_value_to_list(&head3, 2);
    add_value_to_list(&head3, 3);


    ListNode head4(1);
    add_value_to_list(&head4, 2);
    add_value_to_list(&head4, 4);
    add_value_to_list(&head4, 5);

    ListNode * head5 = NULL;
    //if (!so.swapPairs(head5))
        //cout<<"NULL"<<endl;
    print_list(so.swapPairs(&head3));
    //so.swapPairs(&head2);
}
