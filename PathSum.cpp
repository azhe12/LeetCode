/*  azhe_liu
 *  liuyuanzhe123@126.com
 *  2014/4/11
 *
 * */
#include <iostream>
using namespace std;

/**
 * Definition for binary tree
**/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool recursion(TreeNode* root, int pathSum, int sum) {
        if (root == NULL)
            return 0;
        pathSum += root->val;

        if (root->left == NULL && root->right == NULL) {
            if (pathSum == sum)
                return 1;
            else
                return 0;
        }
        if ((root->left != NULL) && recursion(root->left, pathSum, sum))
            return 1;

        if ((root->right != NULL) && recursion(root->right, pathSum, sum))
            return 1;

        return 0;
    }

    bool hasPathSum(TreeNode *root, int sum) {
        return recursion(root, 0, sum);
    }
};

int main()
{
    struct TreeNode t1(1);
    struct TreeNode t2(2);
    struct TreeNode t3(3);
    struct TreeNode t4(1);
    struct TreeNode t5(2);
    struct TreeNode t6(3);

    class Solution so;

    t1.left = &t2;
    t1.right = &t3;

    t2.left = &t4;
    t4.left = &t6;
    
    cout<<so.hasPathSum(&t1, 4)<<endl;
    return 0;
}
