/*  azhe
 *  2014/6/8
 *  https://oj.leetcode.com/problems/triangle/
 *  Node: DFS+DP
 * */
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int DFS(vector<vector<int> > & tri, vector<vector<int> > &minPath, 
                int dep, int col, int maxDep)
    {
        if (minPath[dep][col] == -1) {
            if (dep == maxDep) {
                minPath[dep][col] = tri[dep][col];
            } else {
                minPath[dep][col] = tri[dep][col] + \
                                    min(DFS(tri, minPath, dep+1, col, maxDep), \
                                        DFS(tri, minPath, dep+1, col+1, maxDep));
            }
        }
        return minPath[dep][col];
    }
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.size() == 0)
            return 0;
        vector<vector<int> > minPath;
        for (int i = 0; i < triangle.size(); i++) {
            vector<int> row;
            row.resize(triangle[i].size(), -1);
            minPath.push_back(row);
        }
        return DFS(triangle, minPath, 0, 0, triangle.size()-1);
    }
};
