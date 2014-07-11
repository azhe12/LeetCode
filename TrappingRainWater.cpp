/*  azhe
 *  2014/6/19
 *  https://oj.leetcode.com/problems/trapping-rain-water/
 *  参考: http://blog.csdn.net/wzy_1988/article/details/17752809
 * */
#include <iostream>
using namespace std;
class Solution {
public:
    int trap(int A[], int n) {
        if (n == 0)
            return 0;
        int sum = 0;
        int * leftMax = new int[n];
        int * rightMax = new int[n];
        int max = A[0];
        for (int i = 0; i < n; i++) {   //从左边遍历，找出每个槽左边的最大值
            if (A[i] > max)
                max = A[i];
            leftMax[i] = max;
        }

        max = A[n-1];
        for (int i = n-1; i >= 0; i--) {//从右边遍历，找出每个槽左边的最大值
            if (A[i] > max)
                max = A[i];
            rightMax[i] = max;
        }
        for (int i = 0; i < n; i++) {   //从左边遍历，找出每个槽可储水量
            int high = min(leftMax[i], rightMax[i]) - A[i];
            if (high > 0)
                sum += high;
        }
        delete [] leftMax;
        delete [] rightMax;
        return sum;
    }
};

int main()
{
    int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution so;
    cout<<so.trap(A, sizeof(A)/sizeof(int))<<endl;
    //cout<<so.trap(A, sizeof(A))<<endl;
}


