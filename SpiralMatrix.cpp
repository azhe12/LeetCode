/*  azhe
 *  2014/5/30
 *  https://oj.leetcode.com/problems/spiral-matrix/
 * */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRes(vector<vector<int> > &matrix, int rStart, int rEnd, int cStart, int cEnd)
    {
        vector<int> res;
        if (rStart > rEnd || cStart > cEnd)
            return res;

        if (rStart == rEnd) {       /*只有一行*/
            for (int i = cStart; i <= cEnd; i++)
                res.push_back(matrix[rStart][i]);
            return res;
        }

        if (cStart == cEnd) {       /*只有一列*/
            for (int i = rStart; i <= rEnd; i++) {
                res.push_back(matrix[i][cStart]);
            }
            return res;
        }

        for (int i = cStart; i <= cEnd; i++) {      /*上，行*/
            res.push_back(matrix[rStart][i]);
        }
        for (int i = rStart + 1; i < rEnd; i++)     /*右，列*/
            res.push_back(matrix[i][cEnd]);

        for (int i = cEnd; i >= cStart; i--)        /*下, 行*/
            res.push_back(matrix[rEnd][i]);

        for (int i = rEnd - 1; i > rStart; i--)     /*左，列*/
            res.push_back(matrix[i][cStart]);

        vector<int> resLittle = getRes(matrix, rStart+1, rEnd - 1, cStart+1, cEnd-1);   /*递归，子矩阵*/

        res.insert(res.end(), resLittle.begin(), resLittle.end());                      /*合并:外圈 与 子矩阵*/
        return res;
    }
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if (matrix.size() == 0)
            return res;
        return getRes(matrix, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
    }
};

int main()
{
    Solution so;
    vector<vector<int> > v;
    int n = 1;
    for (int i = 1; i <= 3; i++) {
        vector<int> v1;
        for (int j = 1; j <= 3; j++) {
            v1.push_back(n++);
        }
        v.push_back(v1);
    } 
    vector<int> res;

    res = so.spiralOrder(v);
    for (int i = 0; i < res.size(); i++)
        cout<<res[i]<<" ";
    cout<<endl;
    return 0; 
}
