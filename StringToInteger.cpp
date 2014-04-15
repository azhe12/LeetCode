/*  azhe_liu
 *  liuyuanzhe123@126.com
 *  2014/4/15
 *
 * */
#include <iostream>
using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        long long x = 0;
        bool possitive = 1;
        int int_max = ((long)1<<31) - 1;
        int int_min = ((long)1<<31);
        if (str == NULL)
            return 0;

        /*1. 过滤掉开头空格*/
        while (*str == ' ')str++;
        /*2. 第一个字符是否是+, - 或者其他符号*/
        if (*str == '+') {
            possitive = 1;
            str++;
        } else if (*str == '-') {
            possitive = 0;
            str++;
        }

        while (*str != '\0') {
            /*3. 非数字, 则非法*/
            if (*str > '9' || *str < '0')
                break;

            x = x * 10 + (*str - '0');
            /*4. 避免溢出*/
            if (possitive && x > int_max)
                return int_max;
            if (!possitive && -x < int_min)
                return int_min;
            str++;
        }

        if (possitive == 0)
            x = -x;
        return x;
    }
};

int main()
{
    class Solution so;
    int i = 2147483648;
    long j = 2147483648;
    int int_max = ((long)1<<31) - 1;
    int int_min = ((long)1<<31);
#if 0
    cout<<so.atoi("123")<<endl;
    cout<<so.atoi("-123")<<endl;
    cout<<so.atoi("-00123")<<endl;
    cout<<so.atoi("  +10")<<endl;
#endif
    //cout<<so.atoi("2147483648")<<endl;
    cout<<so.atoi("-2147483649")<<endl;
    //cout<<so.atoi("214748364")<<endl;
    //cout<<i<<endl;
    //cout<<(int)(j % ((long)1<<32))<<endl;
    //cout<<((long)1<<31) - 1<<endl;
    cout<<int_min<<" "<<int_max<<endl;

    return 0;
}

