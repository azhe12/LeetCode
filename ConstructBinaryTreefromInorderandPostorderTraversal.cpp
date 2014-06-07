/*  azhe
 *  2014/6/7
 *  https://oj.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 * */
#include <iostream>
#include <vector>
#include <algorithm>
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
    typedef vector<int>::iterator It;
    void getRes(TreeNode ** root, It in_b, It in_e, It post_b, It post_e)
    {
        if (in_b > in_e || post_b > post_e)
            return;
        *root = new TreeNode(*post_e);
        It root_index_in = find(in_b, in_e, (*root)->val);
        int leftN = root_index_in - in_b;
        int rightN = in_e - root_index_in;
        getRes(&((*root)->left), in_b, root_index_in-1, post_b, post_b+leftN-1);
        getRes(&((*root)->right), root_index_in+1, in_e, post_b+leftN, post_e-1);
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        TreeNode * root = NULL;
        if (inorder.size() == 0 || postorder.size() == 0)
            return root;
        getRes(&root, inorder.begin(), inorder.end()-1, postorder.begin(), postorder.end()-1);
        return root;
    }
};
