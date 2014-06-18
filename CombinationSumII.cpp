/*  azhe
 *  2014/6/18
 *  https://oj.leetcode.com/problems/combination-sum/
 *  Note: DFS
 *  1. 不能重复
 *  2. 去重: 如果一个数字和前一个数字相等， 且前一个数字在当前的结果数组res中未被使用，那么此重复应该被跳过
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
            if (i > 0 && !used[i-1] && cand[i] == cand[i-1])    //如果上个数字在当前结果数组中未被使用 且 数字重复，则跳过此重复
                continue;
            used[i] = true;
            res.push_back(cand[i]);
            dfs(cand, i+1, tar, sum+cand[i], res);  //不能重复，因此从start=i+1继续dfs
            used[i] = false;
            res.pop_back();
        }
    }
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        results.clear();
        used.clear();
        used.resize(candidates.size(), false);  //表示在当前一个结果数组中，一个数字是否使用过

        vector<int> res;
        sort(candidates.begin(), candidates.end()); //排序
        dfs(candidates, 0, target, 0, res);
        return results;
    }
private:
    vector<vector<int> > results;
    vector<bool> used;
};
