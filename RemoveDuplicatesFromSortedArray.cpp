class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i, j;
        j = 0;
        if (n >= 1)
            j = 1;
        for (i = 1; i < n; i++) {
            if (A[i] != A[i-1])
                A[j++] = A[i];                                              
        }   
        return j;
    }
};
