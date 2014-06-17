/*  azhe
 *  2014/6/17
 *  https://oj.leetcode.com/problems/sudoku-solver/
 *  Note: DFS+回溯
 *  1. 尝试每个1-9数字，如果不是valid sudoku，那么重新选取其他数字，若都不符合返回false, 然后回溯到上个空白的选取
 * */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
class ValidSudoku {
public:
    void printFlag(bool * flag)
    {
        for (int i = 1; i < 10; i++)
            cout<<flag[i]<<" ";
        cout<<endl;
    }
    /*判断数组内是否重复*/
    bool isVaildMarkup(bool* flag, char c)
    {
        if (c == '.')
            return true;
        int num = c - '0';
        if (flag[num]) {
            //cout<<c<<endl;
            //cout<<" dumplit: "<<num<<endl;
            //printFlag(flag);
            return false;
        } else {
            flag[num] = true;
            return true;
        }
    }

    /*行是否合法*/
    bool isVaildRow(vector<vector<char> > & board)
    {
        for (int i = 0; i < 9; i++) {
            bool * flag = new bool[10]();
            for (int j = 0; j < 9; j ++) {
                if (!isVaildMarkup(flag, board[i][j])) {
                    delete [] flag;
                    return false;
                }
            }
            delete [] flag;
        }
        return true;
    }

    /*列是否合法*/
    bool isVaildCol(vector<vector<char> > & board)
    {
        for (int i = 0; i < 9; i++) {
            bool * flag = new bool[10]();
            for (int j = 0; j < 9; j ++) {
                if (!isVaildMarkup(flag, board[j][i])) {
                    delete [] flag;
                    return false;
                }
            }
            delete [] flag;
        }
        return true;
    }


    /*九宫格是否合法*/
    bool isVaildBlock(vector<vector<char> > &board)
    {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                bool * flag = new bool[10]();
                for (int h = 0; h < 3; h++) {
                    for (int k = 0; k < 3; k++) {
                        if (!isVaildMarkup(flag, board[3*i+h][3*j+k])) {
                            delete [] flag;
                            return false;
                        }
                    }
                }
                delete [] flag;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char> > &board) {
        return isVaildRow(board) && isVaildCol(board) && isVaildBlock(board);
    }
};


class Solution : public ValidSudoku{
public:
    bool DFS(vector<vector<char> > &board)
    {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {   //找到空白
                    for (char n = '1'; n <= '9'; n++) {
                        board[i][j] = n;                //填入一个数字
                        if (isValidSudoku(board)) {     //合法数独
                            //cout<<i<<" "<<j<<" try: "<<n<<" valid!"<<endl;
                            if (DFS(board))   //DFS求剩下的空白
                                return true;
                        }
                        //cout<<i<<" "<<j<<" try: "<<n<<" not valid!"<<endl;
                        board[i][j] = '.';   //如果此数字不满足,恢复为以前字母'.'
                    }
                    return false;   //所有1-9都不符合
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char> > &board) {
        DFS(board);
    }
};

void printSudoku(vector<vector<char> > &board)
{
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    string line;
    vector<vector<char> > board;
    while (getline(cin, line)) {
        stringstream s(line);
        vector<char> row;
        char chr;
        while (s>>chr) {
            row.push_back(chr);
        }
        board.push_back(row);
    }
    Solution so;
    //so.solveSudoku2(board);
    so.solveSudoku(board);
    printSudoku(board);
}
