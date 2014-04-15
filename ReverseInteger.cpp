/*  azhe_liu
 *  liuyuanzhe123@126.com
 *  2014/4/15
 *
 * */
#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int r_x = 0;
        while (x != 0) {
            r_x = r_x *  10 + x % 10;
            x /= 10;
        }
        return r_x;
    }
};

int main()
{
    class Solution so;
    cout<<so.reverse(123)<<" "<<so.reverse(1000000003)<<endl;
}
