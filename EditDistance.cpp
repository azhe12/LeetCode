//azhe 2014/6/23
//Note: DP
//1. dp[i][j]表示num1的前i个字母组成的单词 到 num2的前j个字母组成的单词 的dist
//  即num1[0...i-1]到num2[0...j-1]的dist
//2. 注意初始化
//3. 注意dp数组的长度是[len1+1][len2+1]
//
//参考:
//1. http://blog.csdn.net/huaweidong2011/article/details/7727482
//2. http://www.cnblogs.com/easonliu/p/3661537.html
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        vector<vector<int> > dp(len1+1, vector<int>(len2+1, 0));
        //init, 当从长度为0的word转换为其他word的distence
        for (int i = 0; i <= len1; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= len2; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1);
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0:1));
            }
        }
        return dp[len1][len2];
    }
};
