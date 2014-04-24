/*  azhe_liu
 *  liuyuanzhe123@126.com
 *  2014/4/18
 *
 * */
#include <iostream>
using namespace std;

class Solution {
public:
    int bitNum(int x, int i)
    {
        int t = 1;
        for (;i-1 != 0; i--) t *= 10; 
        return (x/t) % 10; 
    }

    bool isPalindrome(int x) {
        int len = 0;
        int t;
        if (x == 0)
            return 1;
        /*负数不是回文*/
        if (x < 0)
            return 0;

        t = x;
        for (len=0; t != 0; len++) {
            t = t / 10;
        }

        for (int i = 1; i <= len/2; i++) {
            if (bitNum(x, i) != bitNum(x, len - i + 1))
                return 0;
        }
        return 1;
    }
};

int main()
{
    class Solution so;
    //int x = 12343211;
    int x = -12;
    cout<<so.isPalindrome(x)<<endl;
}
