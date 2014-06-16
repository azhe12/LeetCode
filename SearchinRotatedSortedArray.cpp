/*  azhe
 *  2014/6/16
 *  https://oj.leetcode.com/problems/search-in-rotated-sorted-array/
 *  Note: 二分法
 *  1. 如果一个array是有序的那么A[r] >= A[l], 继续进行二分法查找
 *  2. 如果一个array不是有序的，A[mid]是target则返回，否则对其左右两部分继续递归查找
 * */
#include <iostream>
using namespace std;

class Solution {
public:
    int binarySearch(int A[], int l, int r, int target)
    {
        if (l > r)
            return -1;
        int mid = (l+r) / 2;
        if (A[mid] == target) {
            return mid;
        } else if (A[mid] < target) {
            return binarySearch(A, mid+1, r, target);
        } else {
            return binarySearch(A, l, mid-1, target);
        }
    }

    int getRes(int A[], int l, int r, int target)
    {
        if (l > r)
            return -1;
        int mid = (l+r) / 2;
        if (A[r] >= A[l]) { //有序，二分法查找
            return binarySearch(A, l, r, target);
        } else {            //无序，左右两个集合都需要查找
            if (A[mid] == target) {  //find!
                return mid;
            } else {            //not find, 左右两个集合都需要查找
                int res = getRes(A, l, mid-1, target);
                if (res == -1) {
                    res = getRes(A, mid+1, r, target);
                }
                return res;
            }
        }
    }
    int search(int A[], int n, int target) {
        return getRes(A, 0, n-1, target);
    }
};

int main()
{
    Solution so;
    int A[] = {6,7,0,1,2,4};
    cout<<so.search(A, 6, 7)<<endl;
    return 0;
}
