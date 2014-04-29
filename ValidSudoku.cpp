#include <iostream>
#include <vector>
using namespace std;

class Solution {
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

int main()
{
    Solution so;
    vector<vector<char> > board;

    for (int i = 0; i < 9; i++) {
        vector<char> row;
        for (int j = 0; j < 9; j++) {
            char c;
            cin>>c;
            row.push_back(c);
            //board[i].push_back(c);
            //cout<<c<<endl;
        }
        board.push_back(row);
        row.clear();
    }
#if 0
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
#endif
#if 1
    if (so.isValidSudoku(board))
        cout<<"vaild"<<endl;
    else
        cout<<"invalid"<<endl;
#endif
    return 0;
}
