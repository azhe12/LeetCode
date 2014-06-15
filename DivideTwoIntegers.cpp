/*  azhe
 *  2014/6/15
 *  https://oj.leetcode.com/problems/divide-two-integers/
 * */
#include <iostream>
using namespace std;

class Solution {
public:
    //int divide(int dividend, int divisor) {
    int divide(int dividend2, int divisor2) {
        long long dividend = dividend2;     //避免-21123123, 变成整数之后的溢出, 因此用long long来保存dividend, divisor
        long long divisor = divisor2;

        if (divisor == 0 || dividend == 0)
            return 0;
        bool positive = true;
        if (dividend > 0 && divisor < 0) {
            divisor = -divisor;
            positive = false;
        } else if (dividend < 0 && divisor > 0){
            dividend = -dividend;
            positive = false;
        } else if (dividend < 0 && divisor < 0) {
            dividend = -dividend;
            divisor = -divisor;
        }
        long long total = 0;
        long long remain = dividend;

        while (remain >= divisor) {
            long long tmp = divisor;
            long long res = 1;    //每次对remain整除的结果
            while (tmp <= remain) {
                tmp *= 2;   //每次都对除数翻倍
                res *= 2;   //对商也翻倍
            }
            remain -= tmp/2;    //计算剩余的数字
            total += res/2;     //已经超过，对商减半，然后累加
        }
        if (!positive)
            total = -total;
        return (int)total;
    }
};

int main()
{
    Solution so;
    //cout<<so.divide(20,3)<<endl;
    //cout<<so.divide(-20,-3)<<endl;
    //cout<<so.divide(2147483647,1)<<endl;
    //cout<<so.divide(-999511578,-2147483648)<<endl;
    cout<<so.divide(1,1)<<endl;
}
