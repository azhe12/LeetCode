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
    bool isSymmetricTwo(TreeNode *p, TreeNode* q) {
        if ((p == NULL && q != NULL) ||
                (p != NULL && q == NULL))
            return 0;
        else if (p == NULL && q == NULL)
            return 1;
        else {
            if (p->val == q->val) { /*判断val*/
                if (isSymmetricTwo(p->left, q->right)) {    /*递归p的左子树和q的右子树*/
                    return isSymmetricTwo(p->right, q->left);   /*递归p的右子树和q的左子树*/
                }
            }
#if 0
            if (p->val == q->val) { /*判断val*/
                if (isSymmetricTwo(p->left, q->right)) {    /*递归p的左子树和q的右子树*/
                    return isSymmetricTwo(p->right, q->left);   /*递归p的右子树和q的左子树*/
                } else
                    return 0;
            } else 
                return 0;
#endif
        }
        return 0;
    }

    bool isSymmetric(TreeNode *root) {
        if (root == NULL)
            return 1;

        return isSymmetricTwo(root->left, root->right);     /*判断左右子树是否mirror对称*/
    }
};

int main()
{
    struct TreeNode t1(1);

    struct TreeNode t2(2);
    struct TreeNode t3(2);

    struct TreeNode t4(3);
    struct TreeNode t5(4);
    struct TreeNode t6(3);
    struct TreeNode t7(4);

    struct TreeNode *ta = NULL;
    struct TreeNode tb(3);
    class Solution so;

    t1.left = &t2;
    t1.right = &t3;

    t2.left = &t4;
    t2.right = &t5;

    t3.left = &t7;
    t3.right = &t6;

    if (so.isSymmetric(&t1))
        cout<<"Tree is symmetric"<<endl;
    else
        cout<<"Tree is no symmetric"<<endl;
}
 

