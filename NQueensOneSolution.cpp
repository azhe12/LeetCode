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
    bool isVaild(int n)
    {
        for (int i = 0; i < n; i++) {
            if ((board[i] == board[n]) || (fabs(n-i) == fabs(board[n]-board[i])))
                return false;
        }
        return true;
    }
    bool getRes(int n, int N)
    {
        if (n == N)
            return true;
        for (int i = 0; i < N; i++) {
            board[n] = i;
            if (isVaild(n)) {   //从0~n行的棋盘有效
                if (getRes(n+1, N)) {
                    return true;
                }
            }
        }
        return false;
    }
    vector<string> nQueen(int n)
    {
        board.clear();
        board.resize(n, -1);
        getRes(0, n);

        vector<string> res(n, string(n, '.'));
        for (int i = 0; i < n; i++) {
            res[i][board[i]] = 'Q';
        }
        return res;
    }
private:
    vector<int> board;
};

int main()
{
    int n;
    vector<string> board;
    cout<<"Enter n: ";
    cin>>n;
    Solution so;
    board = so.nQueen(n);
    for (int i = 0; i < n; i++)
        cout<<board[i]<<endl;
    return 0;
}
