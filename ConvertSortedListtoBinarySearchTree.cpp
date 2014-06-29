//azhe 2014/6/29
//Note: 
#include <vector>
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
 
/**
 * Definition for binary tree
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
//Solution_1: 错误 Memory Limit Exceeded
class Solution_1 {
public:
    TreeNode* getBST(vector<int>& nodes, int start, int end)
    {
        if (start > end)
            return NULL;
        int m = (start + end) / 2;
        TreeNode* root = new TreeNode(nodes[m]);
        root->left = getBST(nodes, start, m - 1);
        root->right = getBST(nodes, m + 1, end);
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        vector<int> nodes;
        while (head != NULL) {
            nodes.push_back(head->val);
        }
        return getBST(nodes, 0, nodes.size()-1);
    }
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        int len = 0;
        ListNode* p = head;
        while (p != NULL) {
            len++;
            p = p->next;
        }

        ListNode* cur = head;
        ListNode* prev = NULL;
        int i = 0;
        while (i < len / 2) {
            prev = cur;
            cur = cur->next;
            i++;
        }
        TreeNode* root = new TreeNode(cur->val);
        //right 
        root->right = sortedListToBST(cur->next);
        //left
        if (prev == NULL) {
            root->left = NULL;
        } else {
            prev->next = NULL;
            root->left = sortedListToBST(head);
        }
        return root;
    }
};

void printTree(TreeNode* root)
{
    if (!root)
        return;
    cout<<root->val<<endl;
    printTree(root->left);
    printTree(root->right);
}
int main()
{
    ListNode head(1);
    ListNode head2(3);
    head.next = &head2;
    Solution so;
    TreeNode* root = so.sortedListToBST(&head);
    printTree(root);
}

