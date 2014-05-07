/*  azhe
 *  2014/5/7
 *  Remove Duplicates from Sorted Array II 
 *  http://oj.leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 *  总结: 合适的例子(包含各种case)很必要
 * */
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int b = 0;
        int f = 1;
        int p = 0;  /*新数组的tail*/
        if (n <= 2)
            return n;

        while (true) {
            while ((f < n) && (A[f] == A[b])) {
                f++;
            }

            int diff = f - b;
            if (diff > 2)   /*重复数字不能超过2个*/
                diff = 2;
            for (int i = 0; i < diff; i++) {    /*移动p指针*/
                //cout<<"P:"<<p<<endl;
                A[p++] = A[b++];
            }
            b = f;

            if (f >= n)
                break;
        }
        return p;
    }
};

int main()
{
    Solution so;
    int A[] = {4, 5, 5, 1, 1, 1, 1, 2, 2};
    int n;
    n = so.removeDuplicates(A, sizeof(A) / sizeof(int));
    cout<<"Len:\t"<<n<<endl;
    for (int i = 0; i < n; i++)
        cout<<A[i]<<" ";
    cout<<endl;

    return 0;
}
