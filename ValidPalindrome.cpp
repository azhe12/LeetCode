/*  azhe
 *  2014/5/14
 *  http://oj.leetcode.com/problems/valid-palindrome/
 *  NOTE: 
 *  1. 注意大小写字母以及数字才是有效的比较字符。
 *  2. tolower()使用
 *  3. 注意每次边界改变时是否有效的判断
 * */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAlphaNum(char c)
    {
        if ((c >= 'A' && c <= 'Z') ||
                (c >= 'a' && c <= 'z') ||
                (c >= '0' && c <= '9'))
            return true;
        else
            return false;
    }
    bool isPalindrome(string s) {
        if (s.size() == 0)
            return true;
        int i = 0;
        int j = s.size() - 1;
        while (i <= j) {
            //cout<<s[i]<<" "<<s[j]<<endl;
            while (!isAlphaNum(s[i])) {
                i++;
                if (i >= s.size())
                    break;
            }
            while (!isAlphaNum(s[j])) {
                j--;
                if (j < 0)
                    break;
            }

            if (i > j)
                break;
            if (tolower(s[i]) != tolower(s[j]))
                return false;
            else {
                i++;
                j--;
            }
        }
        return true;
    }
};

int main()
{
    string s;
    //cout<<"Enter string: ";
    //cin>>s;
    Solution so;
    //s = "A man, a plan, a canal: Panama";
    s = "  ";
    cout<<so.isPalindrome(s)<<endl;
    return 0;
}
