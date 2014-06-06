/*  azhe
 *  2014/6/2
 *  https://oj.leetcode.com/problems/word-search/
 *  Note: DFS
 * */
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    bool getRes(int start, int len, int sr, int sc, int r, int c, vector<vector<bool> > & flag, vector<vector<char> > & board, string & word)
    {
        if (start == len)
            return true;
        if (sr > r ||
                sr < 0 ||
                sc > c ||
                sc < 0 ||
                flag[sr][sc] == true)  /*未过界， 未走过*/
            return false;

        if (board[sr][sc] == word[start]) { /*字母匹配, DFS, 从下个字母开始计算*/
            flag[sr][sc] = true;
            //cout<<"r, c :"<<sr<<" "<<sc<<endl;
            if (getRes(start+1, len, sr, sc+1, r, c, flag, board, word) ||
                    getRes(start+1, len, sr+1, sc, r, c, flag, board, word) ||
                    getRes(start+1, len, sr, sc-1, r, c, flag, board, word) ||
                    getRes(start+1, len, sr-1, sc, r, c, flag, board, word)) {  /*如果向右，下，左，上的任一方向可以走通即可*/
                return true;
            }
        }
        return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
        int r = board.size();
        if (r == 0)
            return false;
        int c = board[0].size();
        if (c == 0)
            return false;
        if (word.size() == 0)
            return false;
        cout<<"r, c "<<r<<" "<<c<<endl;
        vector<bool> v;
        v.resize(c, false);
        //vector<vector<bool> > flag(r, vector<bool>(c, false));    [>是否经过的标志<]
        vector<vector<bool> > flag;    /*是否经过的标志*/
        flag.resize(r, v);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == word[0]) {   /*第一个字母匹配*/
                    flag.clear();
                    //cout<<i<<" "<<j<<endl;
                    if (getRes(0, word.size(), i, j, r-1, c-1, flag, board, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};


int main()
{
    vector<vector<char> > board;
    string line;
    while (getline(cin, line)) {
        istringstream s(line);
        char c;
        vector<char> v;
        while (s>>c) {
            v.push_back(c);
        }
        board.push_back(v);
    }
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    string w1("AB");
    string w2("SEE");
    string w3("ABCB");
    Solution so;
    cout<<"w1: "<<so.exist(board, w1)<<endl;
    cout<<"w2: "<<so.exist(board, w2)<<endl;
    cout<<"w3: "<<so.exist(board, w3)<<endl;
    return 0;
}
