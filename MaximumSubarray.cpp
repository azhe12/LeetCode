/*  azhe
 *  2014/5/29
 *  https://oj.leetcode.com/problems/maximum-subarray/
 *  Note: 
 *  方法1: 分治 divide Conquer  O(NlogN)
 *  方法2: 扫描算法 O(logN)
 * */
#include <iostream>
using namespace std;

class Solution {
public:
    /*1. 扫描*/
    int maxSubArray(int A[], int n) {
        int maxSum;
        int sum = 0;
        
        if (n == 0)
            return 0;

        maxSum = A[0];
        for (int i = 0; i < n; i++) {
            //sum = max(sum + A[i], 0);
            sum = sum < 0 ? A[i] : sum + A[i];
            maxSum = max(sum, maxSum);
        }

        return maxSum;
    }

    int maxSum(int A[], int begin, int end)
    {
        int sum;
        int lmax;
        int rmax;
        int m = (begin + end) / 2;

        if (begin > end)
            return 0;
        if (begin == end)
            return A[begin];

        /*跨中界最大值*/
        sum = 0;
        lmax = A[m];
        for (int i = m; i >= begin; i--) {
            sum += A[i];
            lmax = max(lmax, sum);
        }

        rmax = A[m+1];
        sum = 0;
        for (int j = m+1; j <= end; j++) {
            sum += A[j];
            rmax = max(rmax, sum);
        }
        
        int midMax = rmax + lmax;
        /*左边最大值，右边最大值和跨界最大值, 三者中最大的那个即为结果*/
        int lRMax = max(maxSum(A, begin, m), maxSum(A, m+1, end));
        int resMax = max(midMax, lRMax);
        return resMax;
    }

    /*分治*/
    int maxSubArrayDC(int A[], int n) {
        return maxSum(A, 0, n - 1);
    }
};

int main()
{
    Solution so;
    //int A[] = {−2,1,−3,4,−1,2,1,−5,4};
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    //cout<<so.maxSubArrayDC(A, sizeof(A)/sizeof(int))<<endl;
    cout<<so.maxSubArray(A, sizeof(A)/sizeof(int))<<endl;
    return 0;
}
