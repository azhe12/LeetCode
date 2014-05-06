/*  azhe
 *  2014/5/6
 *  http://oj.leetcode.com/problems/climbing-stairs/
 * */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int recurse(int start, int n, vector<int>& ways)
    {
        if (start > n)
            return 0;
        if (start == n)
            return 1;

        /*  每一步有两种情况: 爬1层或2层
         *  对于一个点出发的路径数，等于上边两种情况之和.
         * */
        if (ways[start] == 0)
            ways[start] = recurse(start + 1, n, ways)  + recurse(start + 2, n, ways);

        return ways[start];
    }
    /*Hint: 动态规划*/
    int climbStairs(int n) {
        vector<int> ways(n+1, 0);
        if (n == 0)
            return 0;
        return recurse(0, n, ways);
        
    }
};

int main()
{
    Solution so;
    int n;
    cout<<"Enter n: ";
    while (cin>>n) {
        cout<<"Ways:\t"<<so.climbStairs(n)<<endl;
        cout<<"Enter n: ";
    }
    return 0;
}
