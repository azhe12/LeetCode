/*  azhe
 *  2014/5/29
 *  https://oj.leetcode.com/problems/jump-game/
 * */
#include <iostream>

using namespace std;

class Solution {
public:
    /*  1. 计算出0-(n-1) 每一步出发可以达到的最远的距离
     *  2. 如果已经记录的最远距离不比i大，说明已经无法达到n-1
     *
     * */
    bool canJump(int A[], int n) {
        if (n == 0)
            return true;
        int maxStep = A[0];
        for (int i = 0; i < n; i++) {
            if (i <= maxStep) {
                maxStep = max(maxStep, i + A[i]);
            } else {
                break;
            }
        }
        return maxStep >= (n-1);
    }
};

int main()
{
    int A1[] = {2,3,1,1,4};
    int A2[] = {3,2,1,0,4};
    int A3[] = {0};

    Solution so;
    cout<<so.canJump(A1, sizeof(A1)/sizeof(int))<<endl;
    cout<<so.canJump(A2, sizeof(A2)/sizeof(int))<<endl;
    cout<<so.canJump(A3, sizeof(A3)/sizeof(int))<<endl;
}
