/*  azhe
 *  2014/6/2
 *  https://oj.leetcode.com/problems/combinations/
 * */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void getRes(vector<vector<int> >& res, vector<int>& tmp, int k, int last, int n)
    {
        if (k == 0) {
            res.push_back(tmp);
            return;
        }
        for (int i = last; i <= n; i++) {
            tmp.push_back(i);
            getRes(res, tmp, k-1, i+1, n);      /*递归为求在[last, n]中求k-1的组合*/
            tmp.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> tmp;
        if (n == 0 || n < k)
            return res;

        getRes(res, tmp, k, 1, n);
        return res;
    }
};
