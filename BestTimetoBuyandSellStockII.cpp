/*  azhe
 *  2014/6/8
 *  https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 *  Note: 找出 所有递增子序列 之和
 * */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0)
            return 0;
        int pre = prices[0];            /*前一天的prices*/
        int start = prices[0];          /*递增序列开始的价格*/
        int sum = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < pre) {
                sum += pre - start;
                start = prices[i];
            }
            pre = prices[i];
        }

        sum += pre - start; /*加上最后一段递增序列*/
        return sum;
    }
};
