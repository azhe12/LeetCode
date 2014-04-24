/*  azhe_liu
 *  liuyuanzhe123@126.com
 *  2014/4/24
 *
 * */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int bracketIndex(char c) {
        switch (c) {
            case '(':
            case ')':
                return 1;
            case '[':
            case ']':
                return 2;
            case '{':
            case '}':
                return 3;
        }
    }

    bool isClose(char x, char y) {
        return bracketIndex(x) == bracketIndex(y)?1:0;
    }

    /*判断是否是左括号*/
    bool isBracketLeft(char c) {
        switch (c) {
            case '(':
            case '[':
            case '{':
                return 1;
            default:
                return 0;
        }
    }

    /*判断是否是右括号*/
    bool isBracketRight(char c) {
        switch (c) {
            case ')':
            case ']':
            case '}':
                return 1;
            default:
                return 0;
        }
    }


    void show(const vector<char>& v) {
        for (vector<char>::const_iterator it=v.begin(); it != v.end(); it++) {
            cout<<*it;
        }
        cout<<endl;
    }
    bool isValid(string s) {
        vector<char> brackets;
        for (int i = 0; i < s.size(); i++) {
            if (isBracketLeft(s[i])) {  /*左括号*/
                brackets.push_back(s[i]);
            } else if (isBracketRight(s[i])){   /*右括号*/
                //show(brackets);
                if (brackets.size() == 0)
                    return 0;
                if (isClose(brackets.back(), s[i])) {   /*括号成对出现*/
                    brackets.pop_back();
                } else {
                    return 0;
                }
            }
        }
        if (brackets.size() > 0)
            return 0;
        else
            return 1;
    }
};


int main()
{
    class Solution so;
    string s;
    while (cin>>s) {
        if (so.isValid(s))
            cout<<"valid"<<endl;
        else
            cout<<"invalid"<<endl;   
    }
}
