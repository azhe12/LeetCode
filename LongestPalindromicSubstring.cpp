/*  azhe
 *  2014/6/15
 *  https://oj.leetcode.com/problems/longest-palindromic-substring/
 *  Note:
 *  1. 回文长度分为奇数和偶数，前者的对称点是单个字母，后者的对称点是空白
 *  2. 奇数对称点有n个，偶数对称点有n-1个，总共2n-1个
 *  3. 以每个对称点为中心, 向两边扩展, 回文满足s[left]==s[right]
 *  4. 注意:s[i,i]都是长度为1的回文.
 * */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    //从某个中间点往两边展开
    //若最长回文是奇数, 起始的left==right则中间点为s[left]，
    //若最长回文是偶数，起始right=left+1则中间点为left和right之间的空白
    int getLongestFromMid(string &s, int & left, int & right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        left++;
        right--;
        return right - left + 1;
    }
    string longestPalindrome(string s) {
        int longest = 0;
        int res_left = 0;
        int res_right = 0;
        string res;
        if (s.size() == 0)
            return res;

        for (int i = 0; i < s.size()-1; i++) {
            //以i为对称点, 长度为奇数的最长回文
            int left = i;
            int right = i;
            int longest_odd = getLongestFromMid(s, left, right);
            if (longest_odd > longest) {
                longest = longest_odd;
                res_left = left;
                res_right = right;
            }
            //以i和i+1之间的空白为对称点, 长度为奇数的最长回文
            left = i;
            right = i+1;
            int longest_even = getLongestFromMid(s, left, right);
            if (longest_even > longest) {
                longest = longest_even;
                res_left = left;
                res_right = right;
            }
        }
        return s.substr(res_left, res_right-res_left+1);
    }
};

int main()
{
    //string s("abcbdbcb");
    string s("bb");
    Solution so;
    cout<<so.longestPalindrome(s)<<endl;
    return 0;
}
