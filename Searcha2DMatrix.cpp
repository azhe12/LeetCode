/*  azhe
 *  2014/6/2
 *  https://oj.leetcode.com/problems/search-a-2d-matrix/
 * */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        /*  二维数组在内存中是线性存储， 二分法求解
         *
         * */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int r = matrix.size();
        if (r == 0)
            return false;
        int c = matrix[0].size();
        if (c == 0)
            return false;
        int begin = 0;
        int end = r*c - 1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (matrix[mid/c][mid%c] == target)
                return true;
            else if (matrix[mid/c][mid%c] < target)
                begin = mid + 1;
            else if (matrix[mid/c][mid%c] > target)
                end = mid - 1;
        }
        return false;
    }
};
