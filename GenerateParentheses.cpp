/*  azhe
 *  2014/5/21
 *  https://oj.leetcode.com/problems/generate-parentheses/
 * */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void getAns(string par, vector<string>& res, int left, int right)
    {
        if (left == 0 && right == 0) {      /*若左右括号都用完，返回*/
            res.push_back(par);
            return;
        }

        /*  1. 有两种可能，1) 放左括号 2)放右括号
         *  2. 若剩余左括号数>0则，可以放置左括号
         *  3. 若left < right, 余下的左括号比右括号少，即已经放置的左括号比右括号多，则可以放置右括号
         * */
        if (left > 0) {
            getAns(par + "(", res, left-1, right);
        }

        if (left < right) {
            getAns(par + ")", res, left, right-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        getAns("", res, n, n);
        return res;
    }
};

int main()
{
    vector<string> res;
    Solution so;
    int n;
    while (true) {
        cout<<"Enter n: ";
        if (cin>>n) {
            res = so.generateParenthesis(n);
            for (int i = 0; i < res.size(); i++) {
                cout<<res[i]<<" ";
            }
            cout<<endl;
        } else
            break;
    }
}
