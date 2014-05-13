/*  azhe
 *  2014/5/13
 *  http://oj.leetcode.com/problems/pascals-triangle/
 * */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > rows;
        vector<int> row;
        vector<int> prev;

        if (numRows == 0)
            return rows;

        if (numRows == 1) {
            row.push_back(1);
            rows.push_back(row);
            return rows;
        }
        
        prev.push_back(1);
        rows.push_back(prev);
        for (int j = 2; j <= numRows; j++) {
            row.resize(prev.size() + 1);    /*当前行比上一行多1个*/
            row[0] = 1;                     /*第一个和最后一个数字是1*/
            row[row.size() - 1] = 1;

            for (int i = 1; i < row.size() - 1; i++) {
                row[i] = prev[i - 1] + prev[i];
            }
            rows.push_back(row);
            prev = row;
        }
        return rows;
    }
};


