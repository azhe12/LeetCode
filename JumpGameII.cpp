/*  azhe
 *  2014/5/29
 *  https://oj.leetcode.com/problems/jump-game-ii/
 *  Note: 贪心算法
 *  1. 每次都找到可以跳跃的最远的index,并记录到cur中。
 * */
#include <iostream>
using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        int i = 0;
        int cur;
        int maxStep = 0;
        int step = 0;
        if (n == 0)
            return 0;
        /*n=1时，step=0, 即不许要跳跃*/
        while (i < n - 1) {
            if (A[i] + i >= n - 1) {    /*超过边界*/
                step++;
                return step;
            }
            maxStep = 0;
            for (int j = 1 + i; j <= A[i] + i; j++) {
                if (j + A[j] >= maxStep) {
                    cur = j;
                    maxStep = A[j] + j;     /*当前可达到最远的index*/
                }
            }
            step++;
            i = cur;
            //cout<<"i= "<<i<<endl;
        }
        return step;
    }
};

int main()
{
    Solution so;
    //int A[] = {2,3,1,1,4};
    //int A[] = {1,1,1,1};
    //int A[] = {5,9,3,2,1,0,2,3,3,1,0,0};
    int A[] = {0};
    cout<<so.jump(A, sizeof(A)/sizeof(int))<<endl;
    return 0;
}
