/*
 *  azhe
 *  2014/4/27
 * */
#include <iostream>

//using std::cout;
using namespace std;

class Solution {
public:
    //更优答案O(lgN) http://blog.csdn.net/maqingli87/article/details/8009281
    int searchInsert(int A[], int n, int target) {
        int i;

        for (i = 0; i != n; i++) {
            if (target <= A[i])
                break;
        }

        if (i == n)
            return n;
        else
            return i;
    }
};

void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout<<a[i]<<endl;
}
int main()
{
    Solution so;
    int a[] = {1,3,5,6};
    int target = 7;
    //cout<<so.searchInsert(a, sizeof(a), target)<<endl;
    cout<<so.searchInsert(a, 4, target)<<endl;
    cout<<sizeof(a)/<<endl;
    return 0;
}

