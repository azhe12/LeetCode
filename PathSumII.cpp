/*  azhe
 *  2014/5/13
 *  http://oj.leetcode.com/problems/path-sum-ii/
 *  DFS
 * */

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
    void PathRecur(TreeNode * root, vector<int> path, vector<vector<int> >& res, int sumNow, int sum)
    {
        if (root == NULL)
            return;
        sumNow += root->val;
        path.push_back(root->val);

        if ((root->left == NULL) && (root->right == NULL)) {    /*leaf*/
            if (sumNow == sum) {
                cout<<"Now path to leaf: "<<root->val<<endl;
                res.push_back(path);    /*Find! a new result path*/
            }
            return;
        }

        if (root->left)
            PathRecur(root->left, path, res, sumNow, sum);

        if (root->right)
            PathRecur(root->right, path, res, sumNow, sum);

        return;
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> path;
        vector<vector<int> > res;
        int sumNow = 0;

        PathRecur(root, path, res, sumNow, sum);
        return res;
    }
};
#if 0
int main()
{
    struct TreeNode t1(5);
    struct TreeNode t2(4);
    struct TreeNode t3(8);
    struct TreeNode t4(11);
    struct TreeNode t5(13);
    struct TreeNode t6(4);
    struct TreeNode t7(7);
    struct TreeNode t8(2);
    struct TreeNode t9(5);
    struct TreeNode t10(1);

    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;
    t3.left = &t5;
    t3.right = &t6;
    t4.left = &t7;
    t4.right = &t8;
    t6.left = &t9;
    t6.right = &t10;

    vector<vector<int> > res = pathSum

    return 0;
}
#endif
