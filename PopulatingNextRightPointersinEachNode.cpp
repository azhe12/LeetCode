/*  azhe
 *  2014/6/8
 *  https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/
 *  Note: BFS
 *  1. 注意pre的复制
 * */
#include <queue>
#include <iostream>
using namespace std;
/**
 * Definition for binary tree with next pointer.
 */
 struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };
 
class Solution {
public:
    void bfs(queue<TreeLinkNode *> q)
    {
        TreeLinkNode * pre = NULL;
        queue<TreeLinkNode *> children;
        if (q.size() == 0)
            return;
        while (!q.empty()) {
            TreeLinkNode * tmp = q.front();
            q.pop();
            if (tmp) {
                children.push(tmp->left);
                children.push(tmp->right);
                if (pre)
                    pre->next = tmp;
                pre = tmp;
            }
        }
        if (pre)
            pre->next = NULL;
        bfs(children);

    }
    void connect(TreeLinkNode *root) {
        if (!root)
            return;
        queue<TreeLinkNode *> q;
        q.push(root);
        bfs(q);
    }
};
