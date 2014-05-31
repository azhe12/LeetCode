/*  azhe
 *  2014/5/31
 *  https://oj.leetcode.com/problems/unique-paths-ii/
 *  Note: DP 动态规划
 *  1. 注意路障
 *  2. 路障可能在sr==r或sc==c这种边界上
 * */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*  @sr:    起始的行坐标
     *  @sc:    起始的列坐标
     *  @r:     总行   
     *  @c:     总列
     *  @grid:  grid
     *  @path:  保存从相应index出发可能的路线
     * */
    int getRes(int sr, int sc, int r, int c, vector<vector<int> > &grid, vector<vector<int> > & path)
    {
        if (path[sr][sc] == -1) {   /*未保存*/
            if (grid[sr][sc] == 1) {        /*路障*/
                path[sr][sc] = 0;
            } else if (sr == r && sc ==c) { /*到终点*/
                path[sr][sc] = 1;
            } else if (sr == r) {           /*行到边界*/
                path[sr][sc] = getRes(sr, sc+1, r, c, grid, path);
            } else if (sc == c) {           /*列到边界*/
                path[sr][sc] = getRes(sr+1, sc, r, c, grid, path);
            } else {                        /*未到边界, 分解为向下+向右的路径之和*/
               path[sr][sc] = getRes(sr+1, sc, r, c, grid, path) + \
                                   getRes(sr, sc+1, r, c, grid, path);
            }
        }
        return path[sr][sc];
    }

    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int r = obstacleGrid.size();
        if (r == 0)
            return 0;
        int c = obstacleGrid[0].size();
        if (c == 0)
            return 0;

        vector<int> v(c, -1);
        vector<vector<int> > path(r, v);    /*将path初始为-1*/
        return getRes(0, 0, r-1, c-1, obstacleGrid, path);
    }
};

int main()
{
    vector<int> c(3, 0);
    vector<vector<int> > grid(3, c);
    //grid[0][1] = 1;
    grid[1][1] = 1;
    Solution so;
    cout<<so.uniquePathsWithObstacles(grid)<<endl;
    return 0;
}
