#include <iostream>
#include <cstdio>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i, j = 0;
        for (i = 0; i < n; i++) {
            if (A[i] != elem) {
                A[j++] = A[i];
            }
        }
        return j;
    }
};

int main()
{
    class Solution *so;
    so = new Solution();
    int A[] = {1,2,3,4,5,2,6};

    int n = sizeof(A)/sizeof(int);
    int len_new = so->removeElement(A, n, 2);
    for (int i = 0; i < len_new; i++) {
        printf("%d\n", A[i]);
    }
    delete so;
}
