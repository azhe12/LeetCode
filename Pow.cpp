/*  azhe
 *  2014/5/28
 *  https://oj.leetcode.com/problems/powx-n/
 * */
#include <iostream>

using namespace std;

class Solution {
public:
    /*时间复杂度 O(logn)*/
    double pow(double x, int n)
    {
        double half;
        if (n == 0)
            return 1.0;

        half = pow(x, n/2);
        if (n % 2 == 0) {
            return half * half;
        } else if (n > 0) { /**/
            return half * half * x;
        } else {
            return half / x * half;
        }
    }
};

int main()
{
    Solution so;
    double x;
    int n;
    while (cin>>x>>n) {
        //cout<<"t"<<endl;
        cout<<"pow("<<x<<", "<<n<<") = "<<so.pow(x, n)<<endl;
    }
}
