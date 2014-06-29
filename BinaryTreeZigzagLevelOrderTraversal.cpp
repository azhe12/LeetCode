//azhe 2014/6/29
//Note:
//1. deque双端队列
//2. 注意leftToRight和rightToLeft的切换
#include <iostream>
#include <vector>
#include <deque>
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
    void getRes(deque<TreeNode*>& q, bool leftToRight)
    {
        vector<int> level;
        deque<TreeNode*> q_child;
        if (q.empty())
            return;

        while (!q.empty()) {
            TreeNode* tmp = q.back();
            q.pop_back();
            if (tmp) {
                level.push_back(tmp->val);
                if (leftToRight) {  //从左到右访问
                    q_child.push_back(tmp->left);
                    q_child.push_back(tmp->right);
                } else {            //从右到左访问
                    q_child.push_back(tmp->right);
                    q_child.push_back(tmp->left);
                }
            }
        }
        if (level.size() > 0) {
            res.push_back(level);
        }
        getRes(q_child, !leftToRight);
    }

    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        res.clear();
        if (!root) {
            return res;
        }
        deque<TreeNode*> q;
        q.push_back(root);
        
        getRes(q, true);
        return res;
    }
private:
    vector<vector<int> > res;
};
