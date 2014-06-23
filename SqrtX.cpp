//azhe 2014/6/23
//https://oj.leetcode.com/problems/sqrtx/
//二分法
//注意: 1. long long避免溢出 2. 最后取整的处理
#include <iostream>
using namespace std;

class Solution {
public:
    //long long 64位避免32位乘法溢出.
    int binarySqrt(long long start, long long end, long long num)
    {
        if (start > end) {//最后未找到整数的开放结果
            if (start * start > num) {  //由于start*start可能大于num，那么减去1 即为结果
                return start - 1;
            } else {
                return start;
            }
        }

        long long mid = (start + end) / 2;
        if (mid * mid == num) {
            return mid;
        } else if (mid * mid < num){
            return binarySqrt(mid+1, end, num);
        } else {
            return binarySqrt(start, mid-1, num);
        }
    }
    int sqrt(int x) {
        if (x == 0)
            return 0;
        if (x == 1)
            return 1;
        return binarySqrt(1, x, x);
    }
};

int main()
{
    Solution so;
    while (true) {
        int n;
        if (cin>>n) {
            cout<<"sqrt("<<n<<") = "<<so.sqrt(n)<<endl;
        } else
            break;
    }
    return 0;
}
