//azhe 2014/6/24
//https://oj.leetcode.com/problems/sort-colors/
//Note: two pointer
//1. 使用i遍历数组
//2. j之前都是0, k之后都是2
//3. 1)若A[i]=0, 则交换A[i] 和 A[j], 并且i++, j++
//   2)若A[i]=2, 则交换A[i]和A[k], k--, 但是i不增长，因为原来的A[k]可能是0或2，需要使用i再次进行判断
//   3)若A[i]=1, 不处理i++
#include <iostream>
using namespace std;
class Solution {
public:
    void swap(int & a, int & b)
    {
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
    void sortColors(int A[], int n) {
        int i = 0;
        int j = 0;
        int k = n - 1;
        while (i <= k) {    //注意是i <= k
            if (A[i] == 0) {
                swap(A[i], A[j]);
                i++;
                j++;
            } else if (A[i] == 2) {
                swap(A[i], A[k]);
                k--;
            } else {
                i++;
            }
        }
    }
};

int main()
{
    Solution so;
    int A[] = {1,0};
    //int A[] = {2,0};
    int n = sizeof(A)/sizeof(int);
    so.sortColors(A, sizeof(A)/sizeof(int));
    for (int i = 0; i < n; i++)
        cout<<A[i]<<endl;
}
