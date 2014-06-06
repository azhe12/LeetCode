/*  azhe
 *  2014/6//5
 *  https://oj.leetcode.com/problems/validate-binary-search-tree/
 * */
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
    
    bool getRes(TreeNode * root, int min, int max)
    {
        if (!root)
            return true;
        if (root->val > min && root->val < max) {   /*保证左右边界*/
            return getRes(root->left, min, root->val) && getRes(root->right, root->val, max);   /*更新左右边界*/
        }
        return false;
    }
    bool isValidBST(TreeNode *root) {
        return getRes(root, INT_MIN, INT_MAX);
    }
}; 
