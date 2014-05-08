/*  azhe
 *  2014/5/7
 *  Merge Sorted Array
 *  http://oj.leetcode.com/problems/merge-sorted-array/
 * */
#include <iostream>
using namespace std;

class Solution {
public:
    /*merge_head() 超时，因为从头部比较，因此需要对A进行copy一份，所以timeout*/
    void merge_head(int A[], int m, int B[], int n) {
        int pa = 0;
        int pb = 0;
        int p_new = 0;
        int *A_copy = new int[m];
        //int *A_copy = (int*)malloc(m*sizeof(int));
        for (int i = 0; i < m; i++) {
            A_copy[i] = A[i];
        }

        while (pa < m && pb < n) {
            while (B[pb] < A_copy[pa]) {
                A[p_new] = B[pb];
                pb++;
                if (pb >= n)
                    break;
                p_new++;
            }
            while (A_copy[pa] <= B[pb]) {
                A[p_new] = A_copy[pa];
                pa++;
                if (pa >= n)
                    break;
                p_new++;
            }
        }

        if (pa >= n) {  /*pa overflow*/
            while (pb < n)
                A[p_new++] = B[pb++];
        } else {    /*pb overflow*/
            while (pa < m)
                A[p_new++] = B[pa++];
        }
    }
    /*从尾部开始比较，因此不会覆盖A的前m个元素*/
    void merge(int A[], int m, int B[], int n) {
        int pa = m - 1;
        int pb = n - 1;
        int k = m + n - 1;
        while (pa >= 0 && pb >= 0) {
            while (B[pb] > A[pa]) {
                A[k--] = B[pb--];
                if (pb < 0)
                    break;
            }
            while (A[pa] >= B[pb]) {
                A[k--] = A[pa--];
                if (pa < 0)
                    break;
            }
        }

        if (pa < 0) {   /*A先overflow*/
            while (pb >= 0)
                A[k--] = B[pb--];
        }

        if (pb < 0) {
            while (pa >= 0)
                A[k--] = A[pa--];
        }
    }
};

int main()
{
    Solution so;
    int A[10] = {2, 5, 6, 8};
    int B[] = {1, 7, 9, 10, 11};
    so.merge(A, 4, B, 5);
    for (int i = 0; i < sizeof(A)/sizeof(A[0]); i++)
        cout<<A[i]<<endl;
    cout<<endl;
    return 0;
}
