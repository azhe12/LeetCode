/*  azhe_liu
 *  liuyuanzhe123@126.com
 *  2014/4/11
 *
 * */
#include <iostream>
#include <algorithm>
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
    int maxDepth(TreeNode *root) {
        int max = 0;
        int max_left = 0;
        int max_right = 0;

        if (root == NULL)
            return 0;
        max_left = maxDepth(root->left) + 1;
        max_right = maxDepth(root->right) + 1;

        max = (max_left > max_right) ? max_left:max_right;
        return max;
    }

    /******************
     * 1. NULL是平衡树
     * 2. 左右子树必须都是平衡树
     * 3. 左右子树的高度相差不超过1
     * ***************/
    bool isBalanced(TreeNode *root) {
        int left_depth, right_depth;
        if (root == NULL)       /*1*/
            return 1;

        if (isBalanced(root->left)) {   /*2*/
            if (isBalanced(root->right)) {  /*2*/
                if (abs(maxDepth(root->left) - maxDepth(root->right)) > 1) {    /*3*/
                   return 0; 
                } else {
                    return 1;
                }
            }
        }
        return 0;
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

    class Solution so;

    t1.left = &t2;
    t1.right = &t3;

    t2.left = &t4;
    t3.left = &t6;
    //t4.left = &t6;

    cout<<so.isBalanced(&t1)<<endl;

    return 0;
} 
