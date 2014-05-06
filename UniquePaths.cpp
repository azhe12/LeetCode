/*  azhe
 *  2014/5/5
 *  http://oj.leetcode.com/problems/unique-paths/
 * */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int backtrace(int r, int c, int m, int n, vector<vector<int> > &step)
    {
        if (r == m && c == n)
            return 1;
        if (r > m || c > n)
            return 0;

        if (step[r][c] == -1) { /*如果不存在则计算，避免重复计算*/
            /*从某一点出发到终点，只有2种可能：向右或者向下
             *某一点(r,c)开始路径条数等于 (r+1, c)点开始和(r, c+1)点开始行走的条数之和.
             * */
            /*保存*/
            step[r][c] = backtrace(r+1, c, m, n, step) + backtrace(r, c+1, m, n, step);
        }
        return step[r][c];
    }
    
    /*DP动态规划算法*/
    int uniquePaths(int m, int n) {
        vector<vector<int> > step;
        vector<int> row;
        /*首先申请空间*/
        row.resize(n + 1, -1);
        step.resize(m + 1, row);
        return backtrace(1, 1, m, n, step);
    }

    /*
     *  从n个数中取出m个数的组合
     * */
    int combine(int n, int m)
    {
        if (m == 0 || n == 0)
            return 0;
        if (m > n)
            return 0;
        if (m == n)
            return 1;

        double res = 1;
        /*c(m, n) = ((m+1)*(m+2)*...*(n))/(1*2*...*(n-m))*/
        for (int i = 1; i <= n - m; i++) {
            res *= m+i;
            res /= i;
        }
        return res;
    }
    //
    int uniquePathsCombine(int m, int n)
    {
        return combine(m+n-2, m-1);
    }
};


int main()
{
    Solution so;
    int n, m;
#if 1
    cout<<"Enter m, n: ";
    while (cin>>m>>n) {
        cout<<"DP solution:\t"<<so.uniquePaths(m, n)<<endl;
        cout<<"Combine solution:\t"<<so.uniquePathsCombine(m, n)<<endl;
        cout<<"Enter m, n: ";
    }
#endif
    return 0;
}
