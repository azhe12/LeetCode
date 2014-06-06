/*  azhe
 *  2014/6/6
 *  https://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 *  Note: 
 *  1. DFS 
 *  2. preorder中的第一个即为root节点
 *  3. 在inorder中找到root, 从而将inorder分为左边的左子树 和 右边的右子树
 *  4. 递归分别构建左右子树
 *
 *  PS : 在Solution_iterator中，对size()的判断是必要的。
 *  因为空的vector，begin()和end()是相等的.且有如下性质:
 *  1. end()==begin()
 *  2. end()-1 > begin()    此性质很重要
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
    void getRes(TreeNode ** root, vector<int> & pre, int pre_start, int pre_end, 
                                vector<int> & in, int in_start, int in_end)
    {
        if ((pre_start > pre_end) || (in_start > in_end))
            return;
        *root = new TreeNode(pre[pre_start]);    /*preorder中的第一个即为root节点*/
        vector<int>::iterator tmp = find(in.begin()+in_start, in.begin()+in_end+1, (*root)->val);
        int index = tmp - in.begin();           /*root节点在inorder中的位置*/
        int leftN = index - in_start;
        int rightN = in_end - index;
        getRes(&((*root)->left), pre, pre_start+1, pre_start+leftN, in, in_start, index-1);       /*构建左子树*/
        getRes(&((*root)->right), pre, pre_end-rightN+1, pre_end, in, index+1, in_end);
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        TreeNode * root = NULL;
        getRes(&root, preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
        return root;
    }
};

class Solution_iterator {
    public:
    typedef vector<int>::iterator It;
    void getRes(TreeNode ** root, It pre_start, It pre_end, It in_start, It in_end)
    {
        if ((pre_start > pre_end) || (in_start > in_end))
            return;
        *root = new TreeNode(*pre_start);
        It index = find(in_start, in_end+1, (*root)->val);
        int leftN = index - in_start;
        int rightN = in_end - index;
        getRes(&((*root)->left), pre_start+1, pre_start+leftN, in_start, index-1);
        getRes(&((*root)->right), pre_end-rightN+1, pre_end, index+1, in_end);
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        TreeNode * root = NULL;
        if (preorder.size() != 0 && inorder.size() != 0)
            getRes(&root, preorder.begin(), preorder.end()-1, inorder.begin(), inorder.end()-1);
        return root;
    }
};

