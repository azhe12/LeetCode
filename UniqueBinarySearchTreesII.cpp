//azhe 2014/6/29
//Note: 
//1. 注意dfs的返回值
//2. 结果等于 leftTree情况 乘以 rightTree情况
//
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
    vector<TreeNode *> dfs(int start, int end)
    {
        vector<TreeNode *> res;
        if (start > end) {
            res.push_back(NULL);
            return res;
        }
        for (int i = start; i <= end; i++) {
            vector<TreeNode *> leftTrees = dfs(start, i-1);
            vector<TreeNode *> rightTrees = dfs(i+1, end);
            
            for (int j = 0; j < leftTrees.size(); j++) {
                for (int k = 0; k < rightTrees.size(); k++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftTrees[j];
                    root->right = rightTrees[k];
                    res.push_back(root);
                }
            }

        }
        return res;
    }

    vector<TreeNode *> generateTrees(int n) {
        return dfs(1, n);
    }
};
