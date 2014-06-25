//azhe 2014/6/25
//https://oj.leetcode.com/problems/binary-tree-inorder-traversal/
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
    void inorder(TreeNode * root, vector<int> & res)
    {
        if (!root)
            return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};
