/*  azhe_liu
 *  liuyuanzhe123@126.com
 *  2014/4/11
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
    /*  1. 空节点最小深度为0
     *  2. 最小深度为 从根节点到叶子节点的最短路径
     *  3. 如果一个节点只有一个儿子（左或右），那么只走非空的那条路径
     * */
    int minDepth(TreeNode *root) {
        int left_depth;
        int right_depth;

        if (root == NULL)
            return 0;

        if (root->left == NULL && root->right == NULL)
            return 1;

        left_depth = minDepth(root->left) + 1;
        right_depth = minDepth(root->right) + 1;

        if (root->left == NULL)
            return right_depth;
        else if (root->right == NULL)
            return left_depth;
        else
            return (left_depth < right_depth)?left_depth:right_depth;
        
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
    
    cout<<so.minDepth(&t1)<<endl;
    return 0;
}
