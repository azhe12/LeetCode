#include <iostream>
#include <vector>
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
    //更优答案参考: http://www.cnblogs.com/lautsie/p/3235760.html
    vector<int> searchRange(int A[], int n, int target) {
        int pos = -1;
        pos = binarySearch(A, 0, n-1, target);
        int l = pos;
        int r = pos;
        while (l-1 >= 0 && A[l-1] == target) l--;
        while (r+1 <= n-1 && A[r+1] == target) r++;
        vector<int> res;
        res.push_back(l);
        res.push_back(r);
        return res;
    }
};

int main()
{
    Solution so;
    int A[] = {1};
    vector<int> res;
    res = so.searchRange(A, 1, 1);
    for (int i = 0; i < res.size(); i++)
        cout<<res[i]<<endl;
}
