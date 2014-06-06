/*  azhe
 *  2014/6/2
 *  https://oj.leetcode.com/problems/subsets/
 *  Note: DFS
 *  1. 分为两种情况来将问题分解
 *  2. 第一种: 不添加第一个元素
 *  3. 第二种: 添加第一个元素
 *  4. 去掉重复的元素
 * */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    void getRes(vector<vector<int> > & res, vector<int> tmp, vector<int> &s, int start, int n)
    {
        if (start == n) {
            for (int i = 0; i < res.size(); i++) {
                if (tmp == res[i])
                    return;
            }
            res.push_back(tmp);
            return;
        }

        getRes(res, tmp, s, start+1, n);        /*不添加s[start]*/

#if 0   /*重复计算*/
        tmp.push_back(s[start]);
        getRes(res, tmp, s, start+1, n);        /*添加s[start]*/
#else   /*利用上边getRes的返回结果，避免重复计算*/
        int size = res.size();
        for (int i = 0; i < size; i++) {
            vector<int> v(tmp);
            v.push_back(s[start]);              /*添加s[start]*/
            v.insert(v.end(), res[i].begin(), res[i].end());
            bool skip = false;
            for (int i = 0; i < res.size(); i++) {
                if (v == res[i]) {
                    skip = true;
                    break;
                }
            }
            if (!skip)
                res.push_back(v);
        }
#endif
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > res;
        vector<int> tmp;
        sort(S.begin(), S.end());
        getRes(res, tmp, S, 0, S.size());
        return res;
    }
};

int main()
{
    Solution so;
    int n;
    vector<int> v;
    while (true) {
        //cout<<"Enter n:";
        if (cin>>n) {
            v.push_back(n);
        } else 
            break;
    }
    vector<vector<int> > res;
    res = so.subsetsWithDup(v);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
}
