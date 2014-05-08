/*  azhe_liu
 *  liuyuanzhe123@126.com
 *  2014/4/9
 *
 * */
#include <iostream>
using namespace std;

/**
 * Definition for binary tree
**/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) { /*判断两个二叉树是否相等*/
        if ((p == NULL && q != NULL) || (p != NULL && q == NULL))   /*如果其中一个树的节点已经遍历结束，另外一个却没有，则不等*/
            return 0;
            
        if (p == NULL && q == NULL) /*节点都为NULL*/
            return 1;

        if (p->val == q->val) { /*val相等则继续遍历left和right*/
            if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) {
                return 1;
            }
        }
        return 0;
    }
   
    void treeTraversal(TreeNode *root) {    /*遍历二叉树*/
        if (root == NULL)
            return;

        cout<<root->val<<endl;

        treeTraversal(root->left);
        treeTraversal(root->right);
    }
};

int main()
{
    struct TreeNode t1(1);
    struct TreeNode t2(2);
    struct TreeNode t3(3);

    struct TreeNode t4(1);
    struct TreeNode t5(2);
    struct TreeNode t6(3);

    struct TreeNode *ta = NULL;
    struct TreeNode tb(3);
    class Solution so;

    t1.left = &t2;
    t1.right = &t3;

    t4.left = &t5;
    t4.right = &t6;

    //so.treeTraversal(&t1);
    cout<<so.isSameTree(&t1, &t4)<<endl;
    //cout<<so.isSameTree(ta, &tb)<<endl;
}
