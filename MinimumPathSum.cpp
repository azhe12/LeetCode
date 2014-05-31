/*  azhe
 *  2014/5/31
 *  https://oj.leetcode.com/problems/minimum-path-sum/
 *  Note: DP
 * */
#include <iostream>
#include <vector>
//#include <algorithm>
using namespace std;
class Solution {
public:
    int getRes(int sr, int sc, int r, int c, 
            vector<vector<int> > &grid, 
            vector<vector<int> > &PSum)
    {
        if (PSum[sr][sc] == -1) {   /*未保存*/
            if (sr == r && sc == c) {   /*只有一个点*/
                PSum[sr][sc] = grid[sr][sc];
            } else if (sr == r) {       /*row到边界*/
                PSum[sr][sc] = grid[sr][sc] + getRes(sr, sc+1, r, c, grid, PSum);
            } else if (sc == c) {       /*col到边界*/
                PSum[sr][sc] = grid[sr][sc] + getRes(sr+1, sc, r, c, grid, PSum);
            } else {                    /*未到边界*/
                int minRight = getRes(sr, sc+1, r, c, grid, PSum);
                int minDown = getRes(sr+1, sc, r, c, grid, PSum);
                PSum[sr][sc] = grid[sr][sc] + min(minRight,  minDown);
            }
        }
        return PSum[sr][sc];
    }

    int minPathSum(vector<vector<int> > &grid) {
        int r = grid.size();
        if (r == 0)
            return 0;
        int c = grid[0].size();
        if (c == 0)
            return 0;
        vector<int> v(c, -1);
        vector<vector<int> > PSum(r, v);    /*保存从某点开始的最短路径和*/
        return getRes(0, 0, r-1, c-1, grid, PSum);
#if 0
        int res = getRes(0, 0, r-1, c-1, grid, PSum);
        for (int i = 0; i < PSum.size(); i++) {
            for (int j = 0; j < PSum[i].size(); j++)
                cout<<PSum[i][j]<<" ";
            cout<<endl;
        }
        return res;
#endif
    }
};

int main()
{
    vector<int> v(2,0);
    vector<vector<int> > grid(2, v);
    grid[0][0] = 2;
    grid[0][1] = 1;
    grid[1][0] = 3;
    grid[1][1] = 4;
    Solution so;
    cout<<so.minPathSum(grid)<<endl;
}
