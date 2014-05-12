/*  azhe
 *  2014/5/12
 *  http://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 *  NOTE: 递归和二分法
 * */

#include <iostream>
#include <vector>

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
    TreeNode * BST(int begin, int end, vector<int>& num)
    {
        if (begin > end) {
            return NULL;
        } else if (begin == end) {
            TreeNode * node = new TreeNode(num[begin]);
            return node;
        } else {    /*begin <end*/
            int mid = (begin + end) / 2;
            TreeNode * root = new TreeNode(num[mid]);
            TreeNode * left = BST(begin, mid - 1, num);
            TreeNode * right = BST(mid + 1, end, num);
            root->left = left;
            root->right = right;
            return root;
        }
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.size() == 0)
            return NULL;
        return BST(0, num.size() - 1, num);
    }
};
