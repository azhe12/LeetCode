/*  azhe
 *  2014/6/5
 *  https://oj.leetcode.com/problems/unique-binary-search-trees/
 *  Note: DP+DFS
 *  1. 节点个数相等的BFS, 他们组成树的情况也相等。因为节点内的数字是有序的。
 *  2. DP[n] 表示node总数为n时，BST的可能情况
 *  3. BST的数目只和node数目有关，因此使用dp保存
 * */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int dfs(int n, vector<int> & dp)
    {
        if (dp[n] == 0) {
            if (n == 0 || n == 1) {
                dp[n] = 1;
            } else if (n == 2) {
                dp[n] = 2;
            } else {    /*n>=3*/
                int sum = 0;
                /*依次选取[1,n]作为root来分出左右子树
                 *sum等于左子树的可能情况 乘以 右子树的可能情况
                 * */
                for (int i = 1; i <= n; i++) {
                    sum += dfs(i-1, dp) * dfs(n-i, dp);
                }
                dp[n] = sum;
            }
        }
        return dp[n];
    }
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        return dfs(n, dp);
    }
};

int main()
{
    Solution so;
    cout<<so.numTrees(3)<<endl;
    return 0;
}
