/*  azhe
 *  2014/6/13
 *  https://oj.leetcode.com/problems/palindrome-partitioning/
 *  Note:   DFS
 *  1. 第一个部分的长度分别为1~n, 然后对余下的部分dfs
 * */
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s)
    {
        int start = 0;
        int end = s.size() - 1;
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    void dfs(vector<vector<string> > & res, string & s, int start, int end, vector<string> &parts)
    {
        if (start > end) {
            res.push_back(parts);
            return;
        }

        for (int i = start; i <= end; i++) {        /*第一个部分的长度分别为1~n, 然后对余下的部分dfs*/
            string tmp(s.begin()+start, s.begin()+i+1);     /*注意,end是目标迭代器的下一个位置*/
            if (isPalindrome(tmp)) {
                vector<string> tmp_parts = parts;
                tmp_parts.push_back(tmp);
                dfs(res, s, i+1, end, tmp_parts);
            }
        }
    }

    vector<vector<string> > partition(string s) {
        vector<vector<string> > res;
        vector<string> parts;
        dfs(res, s, 0, s.size()-1, parts);
        return res;
    }
};

int main()
{
    string s("aab");
    Solution so;
    vector<vector<string> > res;
    res = so.partition(s);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
