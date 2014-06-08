/*  azhe
 *  2014/6/8
 *  Note: 以maxProfitDpFromHead() 为准
 * */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int minPrice(vector<int>& prices, int begin, int end)
    {
        int min = prices[begin];
        for (int i = begin; i <= end; i++) {
            if (prices[i] < min)
                min = prices[i];
        }
        return min;
    }

    int maxPrice(vector<int>& prices, int begin, int end)
    {
        int max = prices[begin];
        for (int i = begin; i <= end; i++) {
            if (prices[i] > max)
                max = prices[i];
        }
        return max;
    }

    int profitRecur(vector<int>& prices, int begin, int end)
    {
        int mid = (begin + end) / 2;
        if (begin >= end)
            return 0;

        if (end - begin == 1) {
            if (prices[end] > prices[begin])
                return prices[end] - prices[begin];
            else
                return 0;
        }

        int maxProfitLeft = profitRecur(prices, begin, mid);        /*左边最大利润*/
        int minPriceLeft = minPrice(prices, begin, mid);            /*左边最小单天价格*/

        int maxProfitRight = profitRecur(prices, mid + 1, end);     /*右边最大利润*/
        int maxPriceRight = maxPrice(prices,mid + 1, end);          /*右边最大单天价格*/

        int maxProfitLR = maxPriceRight - minPriceLeft;             /*中间最大利润*/

        //cout<<maxProfitLeft<<" "<<maxProfitRight<<" "<<maxProfitLR<<endl;

        int maxProfit = maxProfitLeft;
        if (maxProfitRight > maxProfit)
            maxProfit = maxProfitRight;

        if (maxProfitLR > maxProfit)
            maxProfit = maxProfitLR;

        if (maxProfit < 0)
            maxProfit = 0;

        return maxProfit;
    }

    int maxProfit(vector<int> &prices) {
        return profitRecur(prices, 0, prices.size() - 1);
    }

    /*动态规划*/
    int maxProfitDP(vector<int> &prices) {
        int maxPrice;
        int maxProfit = 0;
        if (prices.size() == 0)
            return 0;
        maxPrice = prices[prices.size() - 1];       /**/
        for (int i = prices.size() - 1; i >= 0; i--) {
            maxPrice = max(maxPrice, prices[i]);    /*计算i ~ size-1范围的最大值*/
            maxProfit = max(maxProfit, maxPrice - prices[i]);   /*计算最大收益*/
        }
        return maxProfit;
    }

    /*  2014/6/8
     *  1. 一直记录已经扫描过的最小值，然后不断计算当前i与最小值的差，
     *  2. 并记录其中最大的差价，即为结果
     * */
    int maxProfitDpFromHead(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;
        int maxProfit = 0;
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            maxProfit = max(maxProfit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return maxProfit;
    }
};

int main()
{
    vector<int> prices;
#if 1
    prices.push_back(7);
    prices.push_back(11);
    prices.push_back(6);
    prices.push_back(5);
    prices.push_back(20);
    prices.push_back(11);
    prices.push_back(30);
#endif
#if 0
    prices.push_back(3);
    prices.push_back(2);
    prices.push_back(6);
    prices.push_back(5);
    prices.push_back(0);
    prices.push_back(3);
#endif
#if 0
    prices.push_back(2);
    prices.push_back(1);
#endif

    Solution so;
    //cout<<so.maxProfit(prices)<<endl;
    cout<<so.maxProfitDP(prices)<<endl;
    cout<<so.maxProfitDpFromHead(prices)<<endl;
    return 0;
}
