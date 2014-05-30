/*  azhe
 *  2014/5/30
 *  https://oj.leetcode.com/problems/spiral-matrix-ii/
 * */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*  @k: 每个子矩阵第一个数字大小
     *
     * */
    void getRes(vector<vector<int> >& res, int rS, int rE, int cS, int cE, int k)
    {
        if (rS > rE)
            return;
        if (rS == rE) {     /*只有n=1时，会出现*/
            res[rS][cS] = k;
            return;
        }

        int i;
        for (i = cS; i <= cE; i++)
            res[rS][i] = k++;
        for (i = rS + 1; i < rE; i++)
            res[i][cE] = k++;

        for (i = cE; i >= cS; i--)
            res[rE][i] = k++;
        for (i = rE - 1; i > rS; i--)
            res[i][cS] = k++;
            
        //cout<<"k= "<<k<<endl;
        getRes(res, rS+1, rE-1, cS+1, cE-1, k);
    }
    vector<vector<int> > generateMatrix(int n) {
        vector<int> v(n);
        vector<vector<int> > res(n, v);

        getRes(res, 0, n - 1, 0, n - 1, 1);
        return res;
    }
};

int main()
{
    Solution so;

    int n;
    while (true) {
        cout<<"Enter n: ";
        if (cin>>n) {
            vector<vector<int> > res = so.generateMatrix(n); 
#if 0
            for (int i = 0; i < res.size(); i++) {
                for (int j = 0; j < res[i].size)
            }
#endif
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout<<res[i][j]<<" ";
                }
                cout<<endl;
            }
        } else
            break;
    }
    return 0;
}
