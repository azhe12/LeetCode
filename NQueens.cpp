//azhe
//2014/6/21
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    //第n行的棋盘是否有效
    //满足2个条件之一则无效:
    //1. 第n行放置queen的列与前几行放置queen的列相同
    //2. 对角线上queen重复，
    //若0~n-1行上的queen的row和n行上的row之差row_diff 与 col_diff相等，则他们处于对角线上
    bool isVaild(int n, vector<int> & board)
    {
        for (int i = 0; i < n; i++) {
            if ((board[i] == board[n]) || (fabs(n-i) == fabs(board[n]-board[i])))
                return false;
        }
        return true;
    }

    void getRes(int n, int N, vector<int> & board)
    {
        if (n == N) {
            vector<string> boardString(n, string(n, '.'));
            for (int i = 0; i < n; i++) {
                boardString[i][board[i]] = 'Q';
            }
            res_.push_back(boardString);
            return;
        }
        for (int i = 0; i < N; i++) {
            board[n] = i;       //第n行 i列 放置queen
            if (isVaild(n, board)) {    //有效
                getRes(n+1, N, board);
            }
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        res_.clear();
        vector<int> board(n, -1);
        getRes(0, n, board);
        return res_;
    }
private:
    vector<vector<string> > res_;
};

int main()
{
    int n;
    cout<<"Enter n: ";
    while (true) {
        if (!(cin>>n))
            break;
        Solution so;
        vector<vector<string> > res;
        res = so.solveNQueens(n);
        cout<<n<<" Queens have "<<res.size()<<" results"<<endl;
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout<<res[i][j]<<endl;
            }
            cout<<endl<<endl;
        }
    }
    return 0;
}
