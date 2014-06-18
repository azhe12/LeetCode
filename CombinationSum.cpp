/*  azhe
 *  2014/6/18
 *  https://oj.leetcode.com/problems/combination-sum/
 * */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    /*  依次以0~n-1为第一个数字来找结果
     *
     * */
    void dfs(vector<int> &cand, int start, int tar, int sum, vector<int> & res)
    {
        if (sum == tar) {
            results.push_back(res);
            return;
        }
        for (int i = start; 
                i < cand.size() && sum+cand[i] <= tar; i++) {
            res.push_back(cand[i]);
            dfs(cand, i, tar, sum+cand[i], res);
            res.pop_back();
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        results.clear();
        vector<int> res;
        sort(candidates.begin(), candidates.end()); //排序
        dfs(candidates, 0, target, 0, res);
        return results;
    }
private:
    vector<vector<int> > results;
};
