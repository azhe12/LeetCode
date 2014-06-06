/*  azhe
 *  2014/6/2
 *  https://oj.leetcode.com/problems/set-matrix-zeroes/
 * */
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        bool firstrow = false;
        bool firstcol = false;
        int r = matrix.size();
        if (r == 0)
            return;
        int c = matrix[0].size();
        if (c == 0)
            return;
        for (int j = 0; j < c; j++) {
            if (matrix[0][j] == 0)
                firstrow = true;    /*第一行有0*/
        }
        for (int i = 0; i < r; i++) {
            if (matrix[i][0] == 0)       /*第一列有0*/
                firstcol = true;
        }
        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {       /*如果某位为0则，将对应的第一行和第一列的映射点标记为0*/
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < r; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j < c; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 1; j < c; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 0; i < r; i++) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (firstrow) {
            for (int j = 0; j < c; j++)
                matrix[0][j] = 0;
        }
        if (firstcol) {
            for (int i = 0; i < r; i++)
                matrix[i][0] = 0;
        }
    }
};

int main()
{
    string line;
    vector<int> row;
    vector<vector<int> > m;
    /*读标准输入的matrix*/
    while (getline(cin, line)) {
        istringstream stream(line);
        int num;
        while (stream>>num) {
            row.push_back(num);
        }
        m.push_back(row);
        row.clear();
    }

    Solution so;
    so.setZeroes(m);

    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size(); j++) {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
} 
