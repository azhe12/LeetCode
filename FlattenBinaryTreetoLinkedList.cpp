/*  azhe
 *  2014/6/7
 *  https://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list
 *
 * */
#include <vector>
#include <iostream>
using namespace std;
/**
 * Definition for binary tree
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:

    void dfs(TreeNode * root, vector<TreeNode *> & preorder)
    {
        if (!root)
            return;
        preorder.push_back(root);
        dfs(root->left, preorder);
        dfs(root->right, preorder);
    }
    void flatten(TreeNode *root) {
        vector<TreeNode *> preorder;
        dfs(root, preorder);
        /*size()是uint, 如果size()=0, 那么size()-1是一个大整数
         *因此需要下边判断
         * */
        if (preorder.size() <= 1)   
            return;
        for (int i = 0; i < preorder.size() - 1; i++) {
            preorder[i]->left = NULL;       /*注意: 必须将left都设置为NULL*/
            preorder[i]->right = preorder[i+1];
        }
    }
};

void preorder(TreeNode * root)
{
    if (!root)
        return;
    cout<<root->val<<endl;
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode t4(4);
    TreeNode t5(5);
    TreeNode t6(6);
    t1.left = &t2;
    t2.left = &t3;
    t2.right = &t4;
    t1.right = &t5;
    t5.right = &t6;
    Solution so;
    //TreeNode * t = NULL;
    so.flatten(&t1);
    preorder(&t1);
#if 0
    TreeNode * tmp = &t1;
    while (tmp) {
        cout<<tmp->val<<" ";
        tmp = tmp->right;
    }
#endif
}
