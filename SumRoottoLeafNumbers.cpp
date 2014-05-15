#include <iostream>
#include <string>
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
    void sumNumRecur(TreeNode * root, int sumPath, int& sumAllPath)
    {
        if (root == NULL)
            return;

        sumPath *= 10;
        sumPath += root->val;
        if ((root->left == NULL) &&
                (root->right == NULL))  {
            sumAllPath += sumPath;
            return;
        }
        sumNumRecur(root->left, sumPath, sumAllPath);
        sumNumRecur(root->right, sumPath, sumAllPath);
    }

    int sumNumbers(TreeNode *root) {
        int sumAllPath = 0;
        int sumPath = 0;
        sumNumRecur(root, sumPath, sumAllPath);
        return sumAllPath;
    }
};
