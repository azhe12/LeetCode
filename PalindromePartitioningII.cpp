/*  azhe
 *  2014/6/13
 *  https://oj.leetcode.com/problems/palindrome-partitioning-ii/
 * */
#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s, int start, int end)
    {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }


    int dfs(string &s, int start, int end, vector<vector<int> > &dpMin)
    {
        if (start > end)
            return 0;
        if (dpMin[start][end] == INT_MAX) {
            if (isPalindrome(s, start, end)) {  /*整体是回文*/
                dpMin[start][end] = 0;
            } else {                            /*需要分割计算*/
                for (int i = start; i < end; i++) {
                    if (isPalindrome(s, start, i)) {
                        int tmp = 1 + dfs(s, i+1, end, dpMin);
                        dpMin[start][end] = min(tmp, dpMin[start][end]);
                    }
                }
            }
            //cout<<"Save dpMin["<<start<<"]"<<"["<<end<<"] = "<<dpMin[start][end]<<endl;
        }
        return dpMin[start][end];
    }

    int minCut(string s) {
        vector<vector<int> > dpMin(s.size(), vector<int>(s.size(), INT_MAX));   /*将DP初始为INT_MAX*/
        return dfs(s, 0, s.size()-1, dpMin);
    }

    int dfs2(string &s, int start, int end, vector<vector<int> > &dpMin, vector<vector<int> > & palMap)
    {
        if (start > end)
            return 0;
        if (dpMin[start][end] == INT_MAX) {
                            /*需要分割计算*/
                //for (int i = start; i < end; i++) {
            if (palMap[start][end] == -1) {
                palMap[start][end] = isPalindrome(s, start, end);
                if (palMap[start][end]) {
                    dpMin[start][end] = 0;
                    return 0;
                }
            }
            for (int i = end; i >= start; i--) {
                if (palMap[start][i] == -1) {   /*保存对start到i的字串是否为回文的判断结果*/
                    palMap[start][i] = isPalindrome(s, start, i);
                }
                //if (isPalindrome(s, start, i)) {
                if (palMap[start][i] == 1) {
                    int tmp = 1 + dfs(s, i+1, end, dpMin);
                    dpMin[start][end] = min(tmp, dpMin[start][end]);
                }
            }
            cout<<"Save dpMin["<<start<<"]"<<"["<<end<<"] = "<<dpMin[start][end]<<endl;
        }
        //return dpMin[start][end] - 1;
        return dpMin[start][end];
    }

    int minCut2(string s) {
        vector<vector<int> > dpMin(s.size(), vector<int>(s.size(), INT_MAX));   //[>将DP初始为INT_MAX<]
        //vector<int> dpMin(s.size(), vector<int>(s.size(), INT_MAX));   [>将DP初始为INT_MAX<]
        vector<vector<int> > palMap(s.size(), vector<int>(s.size(), -1));
        return dfs2(s, 0, s.size()-1, dpMin, palMap);
    }

};

int main()
{
    Solution so;
    string  s("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");

    //string s("aab");
    //string s("ababa");
    //cout<<so.minCut("aab")<<endl;
    //cout<<so.minCut(s)<<endl;
    cout<<so.minCut2(s)<<endl;
    return 0;
}
