//azhe
//2014/6/20
//1. 一圈一圈的进行 rotate
//2. 依次循环移动0~n-2位上的元素
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n/2; i++) {
            for (int j = i; j < n-i-1; j++) {
                int tmp1 = matrix[i][j];
                int tmp2 = matrix[j][n-i-1];
                int tmp3 = matrix[n-i-1][n-j-1];
                int tmp4 = matrix[n-j-1][i];
                matrix[i][j] = tmp4;
                matrix[j][n-i-1] = tmp1;
                matrix[n-i-1][n-j-1] = tmp2;
                matrix[n-j-1][i] = tmp3;
            }
        }
    }
};
