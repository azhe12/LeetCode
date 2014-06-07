/*  azhe
 *  2014/6/6
 *  https://oj.leetcode.com/problems/binary-tree-level-order-traversal/
 *  Note: BFS
 *  1. 广度优先
 *  2. 先保存root到queue中
 *  3. 然后从头到尾读取queue中的节点，并且依次保存这些节点的子节点到queue<int> children中.
 *  4. 递归重复3
 *  5. 结果进行反向reverse
 * */
#include <iostream>
#include <vector>
#include <queue>
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
    void bfs(queue<TreeNode *> & q, vector<vector<int> > & res)
    {
        queue<TreeNode *> children;
        vector<int> levelE;
        if (q.empty()) {
            return;
        } else {
            while (!q.empty()) {
                TreeNode * tmp = q.front();
                q.pop();
                if (tmp) {
                    levelE.push_back(tmp->val);
                    children.push(tmp->left);
                    children.push(tmp->right);
                }
            }
            if (!levelE.empty())
                res.push_back(levelE);
        }
        bfs(children, res);
    }

    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        vector<vector<int> > res_reverse;
        queue<TreeNode *> q;
        if (root) {
            q.push(root);
            bfs(q, res);
            for (int i = res.size()-1; i >= 0; i--) {
                res_reverse.push_back(res[i]);
            }
        }
        return res_reverse;
    }
};
